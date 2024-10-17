#ifndef PROYECTOE_SISTEMA_H
#define PROYECTOE_SISTEMA_H

#include <string>
#include <vector>
#include "Mesh.h"
#include <sstream>
#include "Vertice.h"
#include "Figura.h"
#include <fstream>
#include <stdexcept>
#include "EmptyStreamException.h"

using namespace std;

class Sistema {
private:
    string nombre;
    vector<Mesh> objetos;

public:

    // Setter para nombre
    void setNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    // Getter para nombre
    string getNombre() const {
        return nombre;
    }

    // Setter para objetos
    void setObjetos(const vector<Mesh>& nuevosObjetos) {
        objetos = nuevosObjetos;
    }

    // Getter para objetos
    vector<Mesh>& getObjetos() {
        return objetos;
    }

    // Método para buscar un Mesh por nombre
 // Método para buscar un Mesh por nombre
  bool buscarMesh(const string& nombre) const {
      for (Mesh mesh : objetos) {
          if (mesh.getNombre() == nombre) {
              return true;
          }
      }
      return false;
  }
Mesh buscarMesh1(const string& nombre) const {
      for (Mesh mesh : objetos) {
          if (mesh.getNombre() == nombre) {
              return mesh;
          }
      }
    return Mesh();
}

    // Método para obtener la cantidad de objetos en memoria
    int cantObjMem() const {
        return objetos.size();
    }

    // Método para agregar un Mesh
    void agregarMesh(const Mesh& mesh) {
        objetos.push_back(mesh);
    }

    // Método para eliminar un Mesh
    void eliminarMesh(const string& nomb) {
        for (int i = 0; i < objetos.size(); i++) {
            if (objetos[i].getNombre() == nomb) {
                objetos.erase(objetos.begin() + i);
                cout << "Objeto " << nomb << " eliminado correctamente" << endl;
                return;
            }
        }
        cout << "Objeto no encontrado" << endl;
    }
//Inicio Comandos



void cargarArchivo(string nombre_archivo) {
  this-> nombre="Sistema";
    Mesh m;
    Vertice v;
    Figura f;
    
    fstream entrada(nombre_archivo);
    if (!entrada.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombre_archivo << std::endl;
        return;
    }

    std::stringstream ss;
    std::string linea;

    while (getline(entrada, linea)) {
        ss << linea << std::endl;
    }
    if (ss.str().empty()) {
        throw EmptyStreamException("El archivo está vacío o no contiene datos válidos.");
    }

    std::string aux1;
    ss >> aux1;
    if (!(buscarMesh(aux1))) {

        m.setNombre(aux1);
        int aux;
        ss >> aux;
        m.setN(aux);
        vector<Vertice> vertices ;
        for (int i = 0; i < m.getN(); ++i) {
            v.setNombre(i);
            ss >> aux;
            v.setX(aux);
            ss >> aux;
            v.setY(aux);
            ss >> aux;
            v.setZ(aux);

            
            vertices.push_back(v);
             // Usando el setter para actualizar el vector
        }
 m.setVertices(vertices);
        int cont = 0;
        while (true) {
             ss >> aux;
             if (aux == -1) {
                 break;
             }
            if (ss.fail()) {
                std::cerr << "Error: Estructura del archivo inválida. No se pudo leer el número de vértices de la figura." << std::endl;
                return;
            }

            f.setCantVert(aux);
            vector<Vertice> verticesFigura;
            for (int i = 0; i < f.getCantVert(); i++) {
                ss >> aux;
                Vertice v1;
                for(int i = 0; i < m.getVertices().size(); i++) {
                    if(m.getVertices()[i].getNombre() == aux) {
                        v1 = m.getVertices()[i]; 
                        verticesFigura.push_back(v1);
                    }
                }
             
                f.setVertices(verticesFigura);  // Usando el setter para actualizar el vector
            }

            vector<Figura> figuras = m.getFiguras();
            figuras.push_back(f);
            m.setFiguras(figuras);  // Usando el setter para actualizar el vector

            cont++;
        }

        vector<Mesh> objetos = getObjetos();
        objetos.push_back(m);
        setObjetos(objetos);  // Usando el setter para actualizar el vector

        std::cout << "Objeto " << m.getNombre() << " cargado correctamente del archivo: " << nombre_archivo << "\n";
    } else {
        std::cout << "El objeto: " << aux1 << " ya existe.\n";
    }
    std::cout << "Cantidad de objetos en memoria: " << cantObjMem() << std::endl;
}

vector<string > vectorStringMallas(){
    vector<string> vectorStrings;
    vector<Mesh> objetos= getObjetos();
    string string1;
    for(int i=0 ; i<objetos.size(); i++){
        string1= "Nombre: " + objetos[i].getNombre() +
                 ", contiene " + to_string(objetos[i].getN()) +
                 " vertices, " + to_string(objetos[i].cantFiguras()) +
                 " caras y "+ to_string(objetos[i].cantAristas()) + " aristas";;
        vectorStrings.push_back(string1);
    }
    return vectorStrings;
}
void listado(  ) {
    int n = cantObjMem();
    vector<string> vectorStrings=vectorStringMallas();

    if(n!=0){
        cout<< "Hay "<< n<< " objetos en memoria:\n";

        for(int i=0; i<vectorStrings.size();i++){
            cout<< vectorStrings[i]<<endl;
        }
    }else {
         cout<< "no hay ningun objeto en memoria\n";
    }

    }



void envolvente(string nombre_objeto) {
    vector<int> auxpmax;
    vector<int> auxpmin;
    vector<Vertice> se;
    vector<Vertice> aux;
    vector<Figura> figurs;

    // Declara la variable `m` de tipo `Mesh`
    Mesh m = buscarMesh1(nombre_objeto); // o Mesh m;

    if(m.getNombre() != "") {
        auxpmax = m.Pmax(); 
        auxpmin = m.Pmin(); 
        string nombre_env = "env_" + nombre_objeto;
        int n = 8;
        int cantvert = 4;

        // Creación de los puntos
        se.push_back(Vertice(0, auxpmin[0], auxpmin[1], auxpmin[2]));
        se.push_back(Vertice(1, auxpmin[0], auxpmin[1], auxpmax[2]));
        se.push_back(Vertice(2, auxpmax[0], auxpmin[1], auxpmax[2]));
        se.push_back(Vertice(3, auxpmax[0], auxpmin[1], auxpmin[2]));
        se.push_back(Vertice(4, auxpmax[0], auxpmax[1], auxpmin[2]));
        se.push_back(Vertice(5, auxpmin[0], auxpmax[1], auxpmin[2]));
        se.push_back(Vertice(6, auxpmin[0], auxpmax[1], auxpmax[2]));
        se.push_back(Vertice(7, auxpmax[0], auxpmax[1], auxpmax[2]));

        // Creación de las caras
        aux.push_back(se[0]);
        aux.push_back(se[1]);
        aux.push_back(se[2]);
        aux.push_back(se[3]);
        Figura f(0, cantvert, aux) ;
        figurs.push_back(f);
        aux.clear();

        aux.push_back(se[0]);
        aux.push_back(se[1]);
        aux.push_back(se[6]);
        aux.push_back(se[5]);
        figurs.push_back(Figura(1, cantvert, aux));
        aux.clear();

        aux.push_back(se[3]);
        aux.push_back(se[4]);
        aux.push_back(se[7]);
        aux.push_back(se[2]);
        figurs.push_back(Figura(2, cantvert, aux));
        aux.clear();

        aux.push_back(se[7]);
        aux.push_back(se[4]);
        aux.push_back(se[5]);
        aux.push_back(se[6]);
        figurs.push_back(Figura(3, cantvert, aux));
        aux.clear();

        aux.push_back(se[0]);
        aux.push_back(se[3]);
        aux.push_back(se[4]);
        aux.push_back(se[5]);
        figurs.push_back(Figura(4, cantvert, aux));
        aux.clear();

        aux.push_back(se[1]);
        aux.push_back(se[6]);
        aux.push_back(se[7]);
        aux.push_back(se[2]);
        figurs.push_back(Figura(5, cantvert, aux));
        aux.clear();

        Mesh me(nombre_env, n, figurs, se);
        agregarMesh(me);
    } else {
        cout << "El objeto: " << nombre_objeto << " no existe.\n";
    }

    }

void envolventeglob(){


     if(cantObjMem()!=0){
         Mesh m;
        vector<Mesh> objetos= getObjetos();
        vector<Mesh>::iterator it;
        m=objetos[0];
    int xmax=0;
    int xmin=m.buscarFigura(0).buscarVertice(0).getX();
    int ymax=0;
    int ymin=m.buscarFigura(0).buscarVertice(0).getY();
    int zmax=0;
    int zmin=m.buscarFigura(0).buscarVertice(0).getZ();;
    vector<int> auxpmax;
    vector<int> auxpmin;
    vector<Vertice>se; 
    vector<Vertice>aux;
    vector<Figura> figurs;
         
    for(it=objetos.begin();it!=objetos.end();it++){
      auxpmax=it->Pmax();
      auxpmin=it->Pmin();
      if(auxpmax[0]>xmax){
        xmax=auxpmax[0];  
      }
      if(auxpmin[0]<xmin){
          xmin=auxpmin[0];
      }
      if(auxpmax[1]>ymax){
          ymax=auxpmax[1];
      }
       if(auxpmin[1]<ymin){
          ymin=auxpmin[1];
      }
       if(auxpmax[2]>zmax){
          zmax=auxpmax[2];
      }
        if(auxpmin[2]<zmin){
          zmin=auxpmin[2];
      }

        auxpmax.clear();
        auxpmin.clear();
    }
      auxpmax.push_back(xmax);
      auxpmax.push_back(ymax);
      auxpmax.push_back(zmax);

      auxpmin.push_back(xmin);
      auxpmin.push_back(ymin);
      auxpmin.push_back(zmin);
      string nombre_env="env_global";
      int n=8;
      int cantvert=4;

      //punto 1
      se.push_back(Vertice(0,auxpmin[0],auxpmin[1],auxpmin[2]));
      //punto 2
      se.push_back(Vertice(1,auxpmin[0],auxpmin[1],auxpmax[2]));
      //punto3 
      se.push_back(Vertice(2,auxpmax[0],auxpmin[1],auxpmax[2]));
      //punto 4
      se.push_back(Vertice(3,auxpmax[0],auxpmin[1],auxpmin[2]));
      //punto 5 
      se.push_back(Vertice(4,auxpmax[0],auxpmax[1],auxpmin[2]));
      //punto 6
      se.push_back(Vertice(5,auxpmin[0],auxpmax[1],auxpmin[2]));
      //punto 7
      se.push_back(Vertice(6,auxpmin[0],auxpmax[1],auxpmax[2]));
      //punto 8
      se.push_back(Vertice(7,auxpmax[0],auxpmax[1],auxpmax[2]));
      //cara 1
      aux.push_back(se[0]);
      aux.push_back(se[1]);
      aux.push_back(se[2]);
      aux.push_back(se[3]);
      figurs.push_back(Figura(0, cantvert, aux));
      aux.clear();
      //cara 2
      aux.push_back(se[0]);
      aux.push_back(se[1]);
      aux.push_back(se[6]);
      aux.push_back(se[5]);
      figurs.push_back(Figura(1, cantvert, aux));
      aux.clear();
      //cara 3
      aux.push_back(se[3]);
      aux.push_back(se[4]);
      aux.push_back(se[7]);
      aux.push_back(se[2]);
      figurs.push_back(Figura(2, cantvert, aux));
      aux.clear();
      //cara 4
      aux.push_back(se[7]);
      aux.push_back(se[4]);
      aux.push_back(se[5]);
      aux.push_back(se[6]);
      figurs.push_back(Figura(3, cantvert, aux));
      aux.clear();
      //cara 5
      aux.push_back(se[0]);
      aux.push_back(se[3]);
      aux.push_back(se[4]);
      aux.push_back(se[5]);
      figurs.push_back(Figura(4, cantvert, aux));
      aux.clear();
      //cara 6
      aux.push_back(se[1]);
      aux.push_back(se[6]);
      aux.push_back(se[7]);
      aux.push_back(se[2]);
      figurs.push_back(Figura(5, cantvert, aux));
      aux.clear();

      Mesh glob(nombre_env,n,figurs,se);
      agregarMesh(glob);

     }else{
         cout<<"No ahi objetos en memoria\n";
     }


    }


void descargar( string nombre_objeto ){    

        Mesh m=buscarMesh1(nombre_objeto);

        if(m.getNombre()!=""){
        std::ofstream file("descarga"+nombre_objeto+".txt");

        file<<"Nombre objeto: "<<m.getNombre()<<endl;
        file<<"Cantidad de vertices: "<<m.getN()<<endl;
        file<<"Cantidad de caras: "<<m.cantFiguras()<<endl; 
        file<<"Cantidad de aristas: "<<m.cantAristas()<<endl;

        eliminarMesh(nombre_objeto);
        cout<<"Objeto "<<nombre_objeto<<" descargado correctamente."<<endl;

         file.close();
        }else{
            cout<<"El objeto "<<nombre_objeto<<" no ha sido cargado en memoria."<<endl;
        }

        }



void guardar( string nombre_objeto,  string nombre_archivo){

        Mesh m=buscarMesh1(nombre_objeto);

           if(m.getNombre()!=""){
           std::ofstream file(nombre_archivo+".txt");

           file<<m.getNombre()<<endl;
           file<<m.getN()<<endl;

           for(int i=0;i<m.getN();i++){
               file<<m.buscarVertice(i).getX()<<" "<<m.buscarVertice(i).getY()<<" "<<m.buscarVertice(i).getZ()<<endl;
           }
            cout<<"CantF:" << m.cantFiguras()<<endl;
           for(int i=0;i<m.cantFiguras();i++){
               cout<< "Nombre: "<< m.buscarFigura(i).impriVertices()<<endl;
               string r=m.buscarFigura(i).impriVertices();
               cout <<"Cant Vert:"<<  m.buscarFigura(i).getCantVert()<<endl;
               file<<m.buscarFigura(i).getCantVert()<<" "<<r<<endl;
           }
           file<<-1<<endl;
               file.close();
           }else{
               cout<<"El objeto "<<nombre_objeto<<" no ha sido cargado en memoria."<<endl;
           }

        }

void v_cercano(double px, double py, double pz, string nombre_objeto) {


        }


void v_cercanos_caja(string nombre_objeto) {


        }


void ruta_corta(int i1, int i2, string nombre_objeto) {


        }


void ruta_corta_centro(int i1, string nombre_objeto) {

        }

void ayuda() {
    cout << "Comandos disponibles:\n";
    cout << "\t- cargar nombre_archivo: Carga en memoria la información de un objeto desde un archivo.\n";
    cout << "\t- listado: Lista los objetos cargados en memoria.\n";
    cout << "\t- envolvente nombre_objeto: Calcula la caja envolvente de un objeto cargado.\n";
    cout << "\t- envolvente1: Calcula la caja envolvente global de todos los objetos cargados en memoria.\n";
    cout << "\t- descargar nombre_objeto: Descarga un objeto de la memoria.\n";
    cout << "\t- guardar nombre_objeto nombre_archivo: Guarda la información de un objeto en un archivo.\n";
    cout << "\t- salir: Termina la ejecución del programa.\n";
}

void Mostrarayuda(string comando) {
    if (comando == "cargar") {
        cout << "Uso: cargar nombre_archivo\n"
                  << "Cargar en memoria la información del objeto nombre_objeto contenida en el archivo identificado por nombre_archivo.\n";
    } else if (comando == "listado") {
        cout << "Uso: listado\n"
                  << "Lista los objetos cargados actualmente en memoria, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras.\n";
    } else if (comando == "envolvente") {
        cout << "Uso: envolvente nombre_objeto\n"
                  << "Calcula la caja envolvente del objeto identificado por nombre_objeto y la agrega a los objetos en memoria.\n";
    } else if (comando == "envolvente1") {
        cout << "Uso: envolvente\n"
                  << "Calcula la caja envolvente de todos los objetos cargados actualmente en memoria y la agrega a los objetos en memoria con el nombre env_global.\n";
    } else if (comando == "descargar") {
        cout << "Uso: descargar nombre_objeto\n"
                  << "Descarga de la memoria toda la información básica (vértices, aristas, caras) del objeto identificado por nombre_objeto.\n";
    } else if (comando == "guardar") {
        cout << "Uso: guardar nombre_objeto nombre_archivo\n"
                  << "Escribe en un archivo de texto, identificado por nombre_archivo, la información básica (vértices y caras) del objeto identificado por nombre_objeto.\n";
    } else if (comando == "v_cercano") {
        cout << "Uso: v_cercano px py pz nombre_objeto\n"
                  << "Identifica el vértice del objeto nombre_objeto más cercano (en términos de la distancia euclidiana) al punto indicado por las coordenadas px, py y pz.\n";
    } else if (comando == "v_cercanos_caja") {
        cout << "Uso: v_cercanos_caja nombre_objeto\n"
                  << "Identifica los vértices del objeto nombre_objeto más cercanos a las esquinas de su caja envolvente.\n";
    } else if (comando == "ruta_corta") {
        cout << "Uso: ruta_corta i1 i2 nombre_objeto\n"
                  << "Identifica la ruta más corta que conecta los vértices i1 y i2 del objeto nombre_objeto.\n";
    } else if (comando == "ruta_corta_centro") {
        cout << "Uso: ruta_corta_centro i1 nombre_objeto\n"
                  << "Identifica la ruta más corta que conecta el vértice i1 con el centro del objeto nombre_objeto.\n";
    } else if (comando == "ayuda") {
        cout << "Uso: ayuda comando\n"
                  << "Muestra la ayuda para el comando especificado.\n";
    } else if (comando == "salir") {
        cout << "Uso: salir\n"
                  << "Termina la ejecución de la aplicación.\n";
    } else {
        cout << "Comando no reconocido. Por favor, intente nuevamente.\n";
    }
}
//Fin Comandos
// Inicio Tokenizar
void tokenizar(std::string comando, std::vector<std::string>& tokenizado){
  std::string token = "";
  tokenizado.clear();

    for (int letra = 0; comando[letra] != '\0'; letra++){
        if (comando[letra] == ' '){
            tokenizado.push_back(token);
            token = "";
        } else {
            token += comando[letra];
        }  
    }
    tokenizado.push_back(token);
}

void menu(std::string comando){

   std::vector<std::string> tokenizado;
     bool ciclo=true;
  do{
    std::cout << "$";
    std::string comando="";
    getline(std::cin, comando);
    tokenizar(comando,tokenizado);

      if(!tokenizado.empty()){
          std::string comando1 = tokenizado[0];
          std::string comando2 = tokenizado.size() > 1 ? tokenizado[1] : "";
          std::string comando3 = tokenizado.size() > 2 ? tokenizado[2] : "";
        if(comando1=="help" && comando2=="cargar" && comando3 ==""){
            std::cout << "Carga en memoria la información del objeto nombre_objeto contenida en el archivo identificado por nombre_archivo. El comando debe estructurar la información a partir del archivo de forma que sea fácil recuperar los datos posteriormente." << std::endl;
        }
        else if(comando1=="help" && comando2=="listado" && comando3 ==""){
            std::cout << "Lista los objetos cargados actualmente en memoria, junto con la información básica de cada uno: cantidad de puntos, de aristas y de caras. << std::endl" ;
        }
        else if(comando1=="help" && comando2=="envolvente" && comando3 ==""){
            std::cout << " Calcula la caja envolvente del objeto identificado por nombre_objeto . Esta caja envolvente se define a partir de dos puntos, pmin y pmax, los cuales determinan los límites de una especie de cuarto donde cabe el objeto completo, es decir, todos los vértices del objeto se encuentran contenidos dentro de la caja (ver figura a continuación). pmin y pmax se calculan como los puntos extremos, en cada dimensión, del conjunto de vértices que define el objeto. La caja envolvente se agrega como un nuevo objeto en memoria, asignándole automáticamente el nombre env_nombre_objeto , para distinguirla de los demás objetos en memoria." << std::endl;
        }
          else if(comando1=="help" && comando2=="descargar" && comando3 ==""){
            std::cout << " Calcula la caja envolvente que incluye a todos los objetos cargados actualmente en memoria Esta caja envolvente se calcula de la misma forma que en el comando anterior, sólo que teniendo en cuenta todos los vértices de todos los objetos en memoria, para no dejar ninguno por fuera de la caja. La caja envolvente se agrega como un nuevo objeto en memoria, asignándole automáticamente el nombre env_global , para distinguirla de los demás objetos en memoria." << std::endl;
        }
        else if(comando1=="help" && comando2=="guardar" && comando3 =="")  {
            std::cout << " Descarga de la memoria toda la información básica (vértices, aristas, caras) del objeto identificado por nombre_objeto." << std::endl;
        }
        else if(comando1=="help" && comando2=="salir" && comando3 ==""){
            std::cout << "Escribe en un archivo de texto, identificado por nombre_archivo, la información básica (vértices y caras) del objeto identificado por nombre_objeto. El archivo debe seguir el formato presentado en la Subsección 1.1." << std::endl;
        }
        else if(comando1=="cargar" && comando2!="" && comando3 ==""){
           cargarArchivo(comando2);
        }
        else if(comando1=="listado" && comando2=="" && comando3 ==""){
        listado();
        }
        else if(comando1=="envolvente" && comando2!=""){
        envolvente(comando2);
        }
        else if(comando1=="envolvente" && comando2=="" && comando3 ==""){
        envolventeglob();
        }
        else if(comando1=="descargar" && comando2!="" && comando3 ==""){
        descargar(comando2);
        }
        else if(comando1=="guardar" && comando2!="" && comando3 !=""){
        guardar(comando2, comando3);
        }
        else if(comando1=="salir" && comando2=="" && comando3 ==""){
            ciclo=false;
        }
      }
  }while(ciclo);
}
//Fin Tokenizar
};

#endif // PROYECTOE_SISTEMA_H
