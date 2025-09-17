#include "TalosOscListener.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "Engine/Engine.h"

ATalosOscListener::ATalosOscListener()
{
    PrimaryActorTick.bCanEverTick = true;
    RecvBuffer.SetNumUninitialized(65536);
}

void ATalosOscListener::BeginPlay()
{
    Super::BeginPlay();

    ISocketSubsystem* Sockets = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
    Socket = Sockets->CreateSocket(NAME_DGram, TEXT("TalosUDP"), false);
    TSharedRef<FInternetAddr> Addr = Sockets->CreateInternetAddr();
    Addr->SetAnyAddress();
    Addr->SetPort(ListenPort);
    bool bOk = Socket->Bind(*Addr);
    if (!bOk)
    {
        UE_LOG(LogTemp, Error, TEXT("Talos UDP bind failed on port %d"), ListenPort);
        return;
    }
    Socket->SetNonBlocking(true);
    UE_LOG(LogTemp, Log, TEXT("Talos UDP listening on %d"), ListenPort);
}

void ATalosOscListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (Socket)
    {
        Socket->Close();
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
        Socket = nullptr;
    }
    Super::EndPlay(EndPlayReason);
}

void ATalosOscListener::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (!Socket) return;

    int32 BytesRead = 0;
    while (Socket->Recv(RecvBuffer.GetData(), RecvBuffer.Num(), BytesRead, ESocketReceiveFlags::None))
    {
        HandlePacket(RecvBuffer.GetData(), BytesRead);
    }

    // Optional: show on screen
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage((uint64)this, 0.f, FColor::Green,
            FString::Printf(TEXT("RPM: %.2f  Angle: %.2f  Fault: %s"),
                LastRPM, LastAngle, *LastFault));
    }
}

void ATalosOscListener::HandlePacket(const uint8* Data, int32 Size)
{
    FString JsonStr = FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(Data)));
    TSharedPtr<FJsonObject> Root;
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(JsonStr);

    if (FJsonSerializer::Deserialize(Reader, Root) && Root.IsValid())
    {
        // Expected format: {"address": "/talos/telemetry", "args": {"rpm":..,"angle":..,"fault":..}}
        const TSharedPtr<FJsonObject>* ArgsObj;
        if (Root->TryGetObjectField(TEXT("args"), ArgsObj))
        {
            double Rpm=0, Angle=0;
            FString Fault;
            (*ArgsObj)->TryGetNumberField(TEXT("rpm"), Rpm);
            (*ArgsObj)->TryGetNumberField(TEXT("angle"), Angle);
            if (!(*ArgsObj)->TryGetStringField(TEXT("fault"), Fault))
            {
                bool bFaultBool=false;
                if ((*ArgsObj)->TryGetBoolField(TEXT("fault"), bFaultBool))
                    Fault = bFaultBool ? TEXT("true") : TEXT("false");
            }
            LastRPM = (float)Rpm;
            LastAngle = (float)Angle;
            LastFault = Fault;
        }
    }
}
