import serial

ser = serial.Serial('COM8', baudrate=9600, timeout=1)


def led_state(x):
    # ser.write(b'1')
    ser.write(bytes(x, 'UTF-8'))
    arduinoData = ser.readline().decode('ascii')
    return arduinoData


while True:
    userInput = input('type 1 for on, 0 for off: ')

    if userInput == '1':
        print(led_state('1'))
    elif userInput == '0':
        print(led_state('0'))
