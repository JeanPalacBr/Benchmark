/* 
 * File:   main.cpp
 * Author: JPBX
 *
 * Created on 6 de marzo de 2020, 02:09 PM
 */

#include <iostream>
#include <thread>
#include <ctime>
#include <chrono>
#include <math.h>
#include <string.h>
#include <fstream>
#include <ctime>
#include <windows.h>


using namespace std;

void primos(int inicial, int ultimo) {
    if (inicial == 3) {
        cout << "2 Es primo" << endl;
    }
    int divcon = 0;
    for (int i = inicial; i <= ultimo; i++) {
        for (int j = 1; j <= (i / 2); j++) {
            if ((i % j) == 0) {
                divcon++;
            }
        }
        if (divcon <= 1) {
            cout << i << " Es primo" << endl;
        }
        divcon = 0;
    }

};

void creayleearchivos(int tamb, double tiempos[2]) {
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<double> fsec;
    auto tl0 = Time::now();
    auto tl1 = Time::now();
    auto te0 = Time::now();
    auto te1 = Time::now();

    fsec tl = tl1 - tl0;
    fsec te = te1 - te0;
    string cadena = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis sagittis est vitae risus dapibus, in viverra risus imperdiet."
            " Vivamus maximus, neque nec pulvinar ullamcorper, arcu augue finibus diam, ac aliquam velit erat vitae tellus. Integer ut imperdiet"
            " magna. Etiam mollis laoreet elit a convallis. Phasellus et dignissim justo. Donec facilisis lacus eu aliquam sodales. Vestibulum "
            "ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Proin bibendum interdum cursus. Vivamus posuere ligula"
            " ut sem ultricies congue. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed et aliquet "
            "lacus, id hendrerit ex. Nulla eu pharetra est. Donec lacus nulla, auctor non fermentum sed, rhoncus ut nibh. Aliquam sed ligula a "
            "sem imperdiet maximus.Proin posuere lacinia facilisis. Mauris convallis tempor felis vel mollis. Phasellus eget pharetra lectus, "
            "sit amet feugiat felis. Pellentesque erat risus, pretium eu placerat eget, porta gravida velit. Fusce vel arcu velit sed.";
    te0 = Time::now();
    ofstream ca("pruebade" + to_string(tamb / 1024) + "MB.txt");
    for (int i = 0; i < tamb; i++) {
        ca << cadena;
    }
    ca.close();
    te1 = Time::now();
    te = te1 - te0;
    tl0 = Time::now();
    ifstream la("pruebade" + to_string(tamb / 1024) + "MB.txt");
    while (!la.eof()) {
        la >> cadena;
    }
    la.close();
    tl1 = Time::now();
    tl = tl1 - tl0;
    tiempos[0] = te.count();
    tiempos[1] = tl.count();
};

int copiaarchivos(double segundos) {
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    string nombrearchivo = "";
    string copia1, copia2 = "";
    typedef std::chrono::duration<double> fsec;
    auto t0 = Time::now();
    auto t1 = Time::now();
    fsec fss = t1 - t0;
    fsec fssaux = t1 - t0;

    int cont = 0;

    system("mkdir \\prueba1");
    system("mkdir \\prueba2");
    string cadena = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis sagittis est vitae risus dapibus, in viverra risus imperdiet."
            " Vivamus maximus, neque nec pulvinar ullamcorper, arcu augue finibus diam, ac aliquam velit erat vitae tellus. Integer ut imperdiet"
            " magna. Etiam mollis laoreet elit a convallis. Phasellus et dignissim justo. Donec facilisis lacus eu aliquam sodales. Vestibulum "
            "ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Proin bibendum interdum cursus. Vivamus posuere ligula"
            " ut sem ultricies congue. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Sed et aliquet "
            "lacus, id hendrerit ex. Nulla eu pharetra est. Donec lacus nulla, auctor non fermentum sed, rhoncus ut nibh. Aliquam sed ligula a "
            "sem imperdiet maximus.Proin posuere lacinia facilisis. Mauris convallis tempor felis vel mollis. Phasellus eget pharetra lectus, "
            "sit amet feugiat felis. Pellentesque erat risus, pretium eu placerat eget, porta gravida velit. Fusce vel arcu velit sed.";
    do {
        nombrearchivo = "pruebade" + to_string(cont) + ".txt";
        ofstream fs("prueba1\\" + nombrearchivo);
        for (int i = 0; i < 4; i++) {
            fs << cadena;
        }
        fs.close();
        auto t0 = Time::now();
        copia1 = "prueba1/" + nombrearchivo;
        copia2 = "prueba2/" + nombrearchivo;
        CopyFileA(copia1.c_str(), copia2.c_str(), TRUE);
        auto t1 = Time::now();
        fss = t1 - t0;
        fssaux = fssaux + fss;
        cont++;
    } while (fssaux.count()<(segundos));
    return cont;
};

int main() {
    void ();
    double tiempo1[2], tiempo2[2], tiempo3[2], tiempo4[2], tiempo5[2];
    double segundos, tte, ttt, ttl = 0;
    double calificacion_hdd = 0;
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<double> fsec;
    auto tpr0 = Time::now();
    auto tpr1 = Time::now();
    fsec tprt = tpr1 - tpr0;

    int op, cantidad_archivos = 0;
    cout << "------------------------------------" << endl;
    cout << "BENCHMARK " << endl;
    cout << "------------------------------------" << endl;
    cout << "A continuación se realizará:" << endl;
    cout << "1. Analisis de  CPU" << endl;
    cout << "2. Analisis de disco duro" << endl;

    cout << "------------------------------------" << endl;
    cout << "REALIZANDO PRUEBA DE CPU" << endl;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA DE BUSQUEDA DE PRIMOS" << endl;
    cout << "------------------------------------" << endl;
    tpr0 = Time::now();
    thread th1{primos, 3, 5000};
    thread th2{primos, 5001, 10000};
    thread th3{primos, 10001, 15000};
    thread th4{primos, 15001, 20000};
    thread th5{primos, 20001, 25000};
    thread th6{primos, 25001, 30000};
    thread th7{primos, 30001, 35000};
    thread th8{primos, 35001, 40000};
    thread th9{primos, 40001, 45000};
    thread th10{primos, 45001, 50000};
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();
    tpr1 = Time::now();
    tprt = tpr1 - tpr0;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA BUSQUEDA DE PRIMOS TERMINADA" << endl;
    cout << "duración: "<<tprt.count()<<" segundos"<<endl;
    cout << "------------------------------------" << endl<<endl;
    
        
    cout << "------------------------------------" << endl;
    cout << "REALIZANDO PRUEBA DE DISCO DURO" << endl;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA DE LECTURA Y ESCRITURA" << endl;
    cout << "------------------------------------" << endl;
    
    creayleearchivos(1024, tiempo1);
    creayleearchivos(10240, tiempo2);
    creayleearchivos(102400, tiempo3);
    creayleearchivos(512000, tiempo4);
    creayleearchivos(1024000, tiempo5);

    cout << "tiempo de escritura para 1MB: " << tiempo1[0] << " segundos" << endl;
    cout << "tiempo de escritura para 10MB: " << tiempo2[0] << " segundos" << endl;
    cout << "tiempo de escritura para 100MB: " << tiempo3[0] << " segundos" << endl;
    cout << "tiempo de escritura para 500MB: " << tiempo4[0] << " segundos" << endl;
    cout << "tiempo de escritura para 1000MB: " << tiempo5[0] << " segundos" << endl;
    cout << "tiempo de lectura para 1MB: " << tiempo1[1] << " segundos" << endl;
    cout << "tiempo de lectura para 10MB: " << tiempo2[1] << " segundos" << endl;
    cout << "tiempo de lectura para 100MB: " << tiempo3[1] << " segundos" << endl;
    cout << "tiempo de lectura para 500MB: " << tiempo4[1] << " segundos" << endl;
    cout << "tiempo de lectura para 1000MB: " << tiempo5[1] << " segundos" << endl;
    ttl = tiempo1[1] + tiempo2[1] + tiempo3[1] + tiempo4[1] + tiempo5[1];
    tte = tiempo1[0] + tiempo2[0] + tiempo3[0] + tiempo4[0] + tiempo5[0];
    ttt = ttl + tte;
    cout << "tiempo total de lectura: " << ttl << " segundos" << endl;
    cout << "tiempo total de escritura: " << tte << " segundos" << endl;
    cout << "tiempo total de escritura + lectura: " << ttt << " segundos" << endl;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA DE COPIADO DE ARCHIVOS" << endl;
    cout << "------------------------------------" << endl;
    cout << "Introduzca tiempo de ejecución para la operación de copiado de archivos." << endl;
    cin>>segundos;
    cantidad_archivos = copiaarchivos(segundos);
    cout << "se copiaron: " << cantidad_archivos << " archivos en " << segundos << " segundos" << endl;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA DE DISCO DURO TERMINADA" << endl;
    cout << "------------------------------------" << endl;
    calificacion_hdd = (((cantidad_archivos / segundos)*0.5)+(ttt * 0.5)) / 2;
    cout << "LA CALIFICACIÓN DE SU DISCO DURO EN LA PRUEBA FUE: " << calificacion_hdd << endl;

    return 0;
    system("pause");
}



