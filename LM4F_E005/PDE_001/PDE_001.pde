/*******************************************************************************
 *
 *                  Graficar temperatura del LM35
 *
 *******************************************************************************
 * FileName:        PDE_001.pde
 * Processor:       EX-LM4F120XL u otro
 * Complier:        Proccesing 3.2.2
 * Author:          Pedro Sánchez Ramírez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     En este ejemplo graficaremos en la señal de temperatura
                    proveniente del sensor LM35.
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      04/11/2016      Creación del firmware
 ******************************************************************************/
 
import processing.serial.*;    // Carga la librería para el manejo de puerto serial     
String portname = "COM13";     // Puerto al que está conectado el Stellaris
Serial puerto;                 // Objeto de puerto
PFont font;                    // Objeto de tipo de fuente
char[] datosc=new char[13];    // Array de almacen de trama recibida en el puerto serie 
int[] datos2=new int[17];      // Array de datos ajustados para guardar en archivo 
float[][] tempe_pantalla = new float[700][4];  // Array para la visualización de datos en pantalla
int muestras;                  // Indica la ubicación donde se almacenará la muestra actual
char inByte;                   // Almacena el byte recibido del puerto serie
int index=0;                   // Index del array de datos de entrada del puerto
float temperatura=0.0;         // Almacena la temperatura
int largew=660;                // Largo de la ventana de la gráfica

 /*******************************************************************************
 * Function:        void setup()
 * Description:     Inicializa los parámetros del programa
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * *****************************************************************************/
void setup() {
  for (int i = 0; i <largew ; i = i+1) {      // Inicializa la matriz de visualización de datos
    for (int j = 0; j <2 ; j = j+1) {
      tempe_pantalla[i][j]=200;
    }
  }
  size(700, 300);                             // Especifica las dimensiones del diálogo
  smooth();                                   // Activa el suavizado de imagen
  font = loadFont("Verdana-16.vlw");          // Carga el tipo de Fuente
  textFont(font);                             // Establece el tipo de fuente
  frameRate (60);                             // Establece el número de ejecuciones de draw() por segundo
  muestras=0;
  index=0;                                   
  puerto = new Serial(this, portname, 9600);  // El último valor es el BaudRate
  puerto.clear();                             // Limpia buffer del puerto
  puerto.buffer(1);                           // El buffer generará el evento SerialEvent al recibir un caracter
}

/*******************************************************************************
 * Function:        void draw()
 * Description:     Función de dibujo del diálogo
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * *****************************************************************************/
void draw() {
  int w;
  background(204);               // Redibuja el diálogo
  stroke(64, 64, 64);            // Establece el color utilizado para dibujar líneas y bordes alrededor de las formas
  fill(63, 102, 150);            // Establece el color de relleno del comando siguiente
  rect(15, 20, 670, 200);        // Ventana de visualización de la gráfica
  stroke(49, 65, 111);
  for (int k = 0; k <=7 ; k++) {
    w=25+25*k;
    line(20, w, 680, w);         // Líneas de división horizontales de la gráfica
  }  
  line(19, 25, 19, 200);         //Lineas verticales de la grafica
  line(680, 25, 680, 200);   
  fill(255, 255, 255);
  rect(22, 233, 10, 10);
  fill(255, 0, 0);
  rect(22, 258, 10, 10);
  fill(0);                                          // Establece el color de relleno del comando siguiente
  text("Bits en el ADC: " + datos2[0], 40, 245);    // Escribe los datos obtenidos en el diálogo
  text("Temperatura: " + temperatura, 40, 270);     // Escribe los datos obtenidos en el diálogo
  text("Gafricar temperatura del LM35", 300, 245);  // Escribe los datos obtenidos en el diálogo
  text("Processing + Stellaris LaunchPad + Energia", 300, 270);  // Escribe los datos obtenidos en el diálogo
  text("http://mrchunckuee.blogspot.com/", 300, 295);  // Escribe los datos obtenidos en el diálogo
  grafiko();                                           // Actualiza la gráfica
}

/*******************************************************************************
 * Function:        void serialEvent()
 * Description:     Atiende un Evento del Puerto Serie
 * Precondition:    None
 * Parameters:      Puerto desde el que se produce la interrupción
 * Return Values:   None
 * Remarks:         None
 * *****************************************************************************/
void serialEvent(Serial puerto_serie) {
  if(puerto_serie==puerto){
    inByte=puerto.readChar();  // Leemos byte recibido
    datosc[index]=inByte;      // Armamos el array
    index++;
    if (index>=4) {
      index=0;
      datos2[0]=datosc[0]+(datosc[1])*256;      // Armamos la variable int
      temperatura = 0.08 * (float)(datos2[0]);  //Calculamos la temperatura
      tempe_pantalla[muestras][0]= 200 - (0.08 * (float)(datos2[0])); //Modificamos los datos para mostrar en pantalla
      muestras=muestras+1;
      if (muestras>=largew) muestras=0;
    }
    puerto.clear();
  }
}

/*******************************************************************************
 * Function:        void grafiko()
 * Description:     Dibuja el Array temperatura en el diálogo
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * *****************************************************************************/
void grafiko() { 
  stroke(255, 0, 0); // Gráfico temperatura
  for (int i = 0; i+muestras-0 <largew-1 ; i = i+1) {  
    line(i+20, tempe_pantalla[i+muestras][0], (i+21), tempe_pantalla[i+muestras+1][0]);
  }
  for (int i = 0; i<muestras-1; i = i+1) {  
    line(i+largew-muestras+20, tempe_pantalla[i][0], (i+largew-muestras+21), tempe_pantalla[i+1][0]);
  }
}

/*******************************************************************************
 * Referencias:
 *  - https://antiepoke.wordpress.com/2013/04/05/puerto-serie-en-processing/
 *  - https://processing.org/
 ******************************************************************************/