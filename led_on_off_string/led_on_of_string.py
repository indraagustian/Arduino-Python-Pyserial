import serial

ser = serial.Serial('COM8', baudrate=9600, timeout=1)


def led_state(x):
    # ser.write(b'1')
    ser.write(bytes(x, 'UTF-8'))
    arduinoData = ser.readline().decode('ascii')
    return arduinoData


while True:
    userInput = input('type on or off: ')

    if userInput == "on":
        print(led_state("on\n"))
    elif userInput == "off":
        print(led_state("off\n"))
