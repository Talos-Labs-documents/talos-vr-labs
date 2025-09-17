import serial, socket, json, threading, os, sys

SERIAL_PORT = os.environ.get("SERIAL_PORT", "/dev/ttyACM0")  # COM3 on Windows
BAUD = int(os.environ.get("BAUD", "115200"))
OSC_TARGET = ("127.0.0.1", int(os.environ.get("OSC_PORT", "9000")))
MAX_RPM = float(os.environ.get("MAX_RPM", "40"))

def send_osc(sock, address, data):
    payload = json.dumps({"address": address, "args": data}).encode("utf-8")
    sock.sendto(payload, OSC_TARGET)

def rx_loop(ser, sock):
    while True:
        line = ser.readline().decode("utf-8", "ignore").strip()
        if not line:
            continue
        try:
            data = json.loads(line)
            send_osc(sock, "/talos/telemetry", data)
        except Exception:
            pass

def main():
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    ser = serial.Serial(SERIAL_PORT, BAUD, timeout=0.2)
    threading.Thread(target=rx_loop, args=(ser, sock), daemon=True).start()

    print("Bridge ready. Send JSON commands on stdin, e.g. {"rpm":20}", flush=True)
    for line in sys.stdin:
        try:
            cmd = json.loads(line.strip())
            rpm = max(min(float(cmd.get("rpm", 0.0)), MAX_RPM), -MAX_RPM)
            ser.write((json.dumps({"rpm": rpm}) + "\n").encode("utf-8"))
        except Exception as e:
            print("Bad command:", e, flush=True)

if __name__ == "__main__":
    main()
