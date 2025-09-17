#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HAL/Runnable.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Interfaces/IPv4/IPv4Endpoint.h"
#include "TalosOscListener.generated.h"

UCLASS(Blueprintable)
class TALOSRIG_API ATalosOscListener : public AActor
{
    GENERATED_BODY()

public:
    ATalosOscListener();
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaSeconds) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Talos|OSC")
    int32 ListenPort = 9000;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Talos|Telemetry")
    float LastRPM = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Talos|Telemetry")
    float LastAngle = 0.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Talos|Telemetry")
    FString LastFault = TEXT("");

private:
    FSocket* Socket = nullptr;
    TArray<uint8> RecvBuffer;
    FCriticalSection DataMutex;
    FString PendingJson;
    void HandlePacket(const uint8* Data, int32 Size);
};
