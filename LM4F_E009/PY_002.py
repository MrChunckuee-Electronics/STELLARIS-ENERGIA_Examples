"""
 *******************************************************************************
 *
 *    Puerto serie - Recepción de datos
 *
 *******************************************************************************
 * FileName:        PY_002.py
 * Complier:        EPython 3.7.1
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Ejemplo de recepcion de datos atravez de un puerto COM
 *                  usando la libreria pySerial.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v0.0.0     22/02/2019      - Creación del firmware
 *   v0.0.1     14/03/2019      - Se modifico para leer datos en una sola linea
 *                              - Se paso de byte a ASCII o UTF-8 y se elimino \r\n
 *******************************************************************************
"""
import serial

#Usamos puerto COM4 a 9600 baudios
PORT = 'COM4'
ser = serial.Serial(PORT, 9600)
print("Connected to: " + ser.portstr)

while True:
    getSerialValue = ser.readline()
    # Byte to Str using decode()
    # using ASCII & UTF-8 mapping
    outputASCII= getSerialValue.decode('ASCII')
    outputUTF8= getSerialValue.decode('UTF-8')
    outputASCII = outputASCII[:-2] # Removes last two characters (\r\n)
    outputUTF8 = outputUTF8[:-2] # Removes last two characters (\r\n)
    print ('Data BYTE:  %s' %getSerialValue)
    print ('Data ASCII: %s' %outputASCII)
    print ('Data UTF-8: %s' %outputUTF8)

