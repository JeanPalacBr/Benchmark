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
#include <math.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <sstream>
#include <iostream>
#include <fstream> 
#define N 250000

using namespace std;

const int x0 = 1, y0 = 0, xf = 211, yf = 212;
const char MURO = '1';
const char LIBRE = '0';
const char USR = '2';
const int TAMLAB = 213;
char lab[TAMLAB][TAMLAB];

void readLab() {
    char lTx[639][639];
    ifstream inFile;
    inFile.open("maze.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1); // call system to stop
    }
    string x;
    int c = 0;
    while (inFile >> x) {
        for (int i = 0; i < x.length(); i++) {
            if (x[i] == '1') {
                lTx[c][i] = MURO;
            } else {
                lTx[c][i] = LIBRE;
            }
        }
        c++;
    }
    for (int i = 0; i < 213; i++) {
        for (int j = 0; j < 213; j++) {
            if (lTx[3 * i][3 * j] == MURO || lTx[3 * i + 1][3 * j] == MURO || lTx[3 * i + 2][3 * j] == MURO ||
                    lTx[3 * i][3 * j + 1] == MURO || lTx[3 * i + 1][3 * j + 1] == MURO || lTx[3 * i + 2][3 * j + 1] == MURO ||
                    lTx[3 * i][3 * j + 2] == MURO || lTx[3 * i + 1][3 * j + 2] == MURO || lTx[3 * i + 2][3 * j + 2] == MURO) {
                lab[i][j] = MURO;
            } else {
                lab[i][j] = LIBRE;
            }
        }
    }
    inFile.close();
}

void writeLab(string name) {
    ofstream file(name);
    for (int i = 0; i < TAMLAB; i++) {
        for (int j = 0; j < TAMLAB; j++) {
            file << lab[i][j];
        }
        file << endl;
    }
    file.close();
}

void cleanLab() {
    for (int i = 0; i < TAMLAB; i++) {
        for (int j = 0; j < TAMLAB; j++) {
            if (lab[i][j] == '1') lab[i][j] = '0';
        }
    }
}

bool solve(int X, int Y) {
    lab[Y][X] = USR;
    if (X == xf && Y == yf) {
        return true;
    }
    if (X > 0 && lab[Y][X - 1] == LIBRE && solve(X - 1, Y)) {
        return true;
    }
    if (X < TAMLAB && lab[Y][X + 1] == LIBRE && solve(X + 1, Y)) {
        return true;
    }
    if (Y > 0 && lab[Y - 1][X] == LIBRE && solve(X, Y - 1)) {
        return true;
    }
    if (Y < TAMLAB && lab[Y + 1][X] == LIBRE && solve(X, Y + 1)) {
        return true;
    }
    lab[Y][X] = MURO;
    return false;
}

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
        ofstream fs("C:\\prueba1\\" + nombrearchivo);
        for (int i = 0; i < 4; i++) {
            fs << cadena;
        }
        fs.close();
        auto t0 = Time::now();
        copia1 = "C:/prueba1/" + nombrearchivo;
        copia2 = "C:/prueba2/" + nombrearchivo;
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
    double calificacion_hdd, calificacion_cpu, cal_pcword, cal_progr, cal_data = 0;
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::milliseconds ms;
    typedef std::chrono::duration<double> fsec;
    auto tpr0 = Time::now();
    auto tmz0 = Time::now();
    auto tpr1 = Time::now();
    auto tmz1 = Time::now();
    auto tdp0 = Time::now();
    auto tdp1 = Time::now();
    fsec tprt, tmzt, tdpt = tpr1 - tpr0;

    int perfil, cantidad_archivos = 0;
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
    cout << "duración: " << tprt.count() << " segundos" << endl;
    cout << "------------------------------------" << endl << endl;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA DE BUSQUEDA DE DIGITOS DE PI" << endl;
    cout << "------------------------------------" << endl;

    int len = floor(10 * N / 3) + 1;
    long long A[len];

    for (int i = 0; i < len; ++i) {
        A[i] = (long long) 2;
    }

    long long nines = (long long) 0;
    long long predigit = (long long) 0;
    std::string number;
    std::stringstream strstream;
    tdp0 = Time::now();
    for (int j = 1; j < N + 1; ++j) {
        long long q = 0;

        for (int i = len; i > 0; --i) {
            long long x = 10 * A[i - 1] + q * (long long) i;
            A[i - 1] = x % (2 * i - 1);
            q = x / (2 * (long long) i - 1);
        }

        A[0] = q % (long long) 10;
        q = q / (long long) 10;

        if ((long long) 9 == q) {
            nines = nines + (long long) 1;
        } else if ((long long) 10 == q) {
            strstream << predigit + (long long) 1;

            for (int k = 0; k < nines; ++k) {
                strstream << 0;
            }
            predigit, nines = 0;
        } else {
            strstream << predigit;
            predigit = q;

            if (0 != nines) {
                for (long long k = (long long) 0; (long long) k < nines; k = k + (long long) 1) {
                    strstream << 9;
                }

                nines = (long long) 0;
            }
        }
    }
    tdp1 = Time::now();
    tdpt = tdp1 - tdp0;
    strstream << predigit;
    strstream >> number;

    std::ofstream outfile("Digits_PI.txt");
    outfile << "Executiontime: ";
    outfile << tdpt.count() << std::endl;
    outfile << number << std::endl;
    outfile.close();
    printf("Terminado");


    cout << "------------------------------------" << endl;
    cout << "PRUEBA BUSQUEDA DE DIGITOS DE PI TERMINADA" << endl;
    cout << "SE HA GENERADO UN ARCHIVO CON LOS RESULTADOS EN LA CARPETA RAIZ" << endl;
    cout << "duración: " <<tdpt.count()<< " segundos" << endl;
    cout << "------------------------------------" << endl << endl;

    cout << "------------------------------------" << endl;

    cout << "------------------------------------" << endl;
    cout << "PRUEBA RESOLUCIÓN DE LABERINTO " << endl;
    cout << "------------------------------------" << endl;

    tmz0 = Time::now();
    readLab();
    writeLab("mazeSmall.txt");
    if (solve(x0, y0)) {
        cout << "Resuelto.";
    }
    cleanLab();
    writeLab("mazeSolution.txt");
    tmz1 = Time::now();
    tmzt = tmz1 - tmz0;

    calificacion_cpu = (((6.89794/(tprt.count()))*0.5)+(((0.0600607)/tmzt.count())*0.25)+(((2889.71)/(tdpt.count()))*0.5))*60;
    cout << "------------------------------------" << endl;
    cout << "PRUEBA RESOLUCIÓN DE LABERINTO TERMINADA" << endl;
    cout << "SE HA GENERADO UN ARCHIVO EN LA CARPETA RAIZ CON LA SOLUCIÓN" << endl;
    cout << "duración: " << tmzt.count() << " segundos" << endl; 
    cout << "------------------------------------" << endl << endl;
    cout << "LA CALIFICACIÓN DE LA CPU ES: " <<calificacion_cpu<<endl;
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
    calificacion_hdd = ((cantidad_archivos/16823.6667)*0.5+(59.751/ttt)*0.5)*60;
    cout << "LA CALIFICACIÓN DE SU DISCO DURO EN LA PRUEBA FUE: " << calificacion_hdd << endl;
    cout << "------------------------------------" << endl;
    cout << "RESULTADOS SEGUN CADA PERFIL" << endl;

    cout << "Computador para “internet y documentos de Word”" << endl;

    cal_pcword = (calificacion_cpu*0.5 + calificacion_hdd*0.5)*1.2;
    if (cal_pcword > 100) {
        cal_pcword = 100;
    }
    cout << "La calificación es:" << cal_pcword << endl;
    cout << "Computador para programar" << endl;
    cal_progr = (calificacion_hdd * 0.6 + calificacion_cpu * 0.4);
    if (cal_progr > 100) {
        cal_progr = 100;
    }
    cout << "La calificación es:" << cal_progr << endl;
    cout << "Computador para procesar analíticas de datos." << endl;
    cal_data = (calificacion_hdd * 0.7 + calificacion_cpu * 0.3) / 1.1;
    if (cal_data > 100) {
        cal_data = 100;
    }
 
    cout << "La calificación es:" << cal_data << endl;
    return 0;
    system("pause");
}