#include "gestionforo.h"
#include "usuario.h"
#include "tema.h"
#include "foro.h"
#include "hilo.h"

Usuario* usuarioActivo = NULL;
Foro* foroActivo = new Foro();
Tema* temaTemp = NULL;
int numTemp = -1;

GestionForo::GestionForo()
{
    devolverForo();
}

void GestionForo::devolverForo(){
    int eleccionForo = -1;
    while (eleccionForo!=0){
        cout << "********************     FORO      *********************" << endl;
        if (usuarioActivo==NULL) cout << "\t\t\t\tUsuario: Invitado" << endl;
        else cout << "\t\t\t\tUsuario: " << usuarioActivo->getAlias() << endl;
        cout << endl;
        cout << "*** 1)\tNumero de Temas                              ***" << endl;
        cout << "*** 2)\tVer Tema                                     ***" << endl;
        cout << "*** 3)\tNuevo Usuario                                ***" << endl;
        cout << "*** 4)\tLogin                                        ***" << endl;
        cout << "*** 5)\tCrear nuevo Tema                             ***" << endl;
        cout << "*** 0)\tSalir                                        ***" << endl;
        cout << endl;
        cout << "********************************************************" << endl;
        cin >> eleccionForo;
        switch(eleccionForo){
        case 0:{
            exit(0);
            break;}
        case 1:{
            // Obtener número de temas
            if (foroActivo == NULL){
                cout << "\nAún no han sido creados Temas para este Foro\n" << endl;
            } else {
                cout << "\nEl número de temas actualmente es " << foroActivo->numTemas() << "\n" << endl;
            }
            break;}
        case 2:{
            // Ver Tema
            int numTema = -1;
            if (foroActivo->numTemas() > 0){
                cout << endl;
                int contador = 0;
                //vector<Tema> *temas = foroActivo->getVectorTema();
                for(Tema & item: *(foroActivo->getVectorTema())){
                    cout << contador << "\t" << item.getDenominacion() << endl;
                    contador++;
                }

                cout << "\nIntroduzca el número de tema que desea ver: " << endl;
                cin >> numTema;
                if(numTema>=0 && numTema<foroActivo->getVectorTema()->size()){
                    eleccionForo = -1;
                    numTemp = numTema;
                    this->devolverTema(numTema);
                    cout << endl;
                } else cout << "\nIntroduzca un número de Tema correcto\n" << endl;
            } else {
                cout << "\nAún no han sido creados Temas para este Foro\n" << endl;
            }
            break;}
         case 3:{
            // Crear nuevo usuario
            string nombre, alias, clave;
            cout << "\nIntroduzca su nombre:" << endl;
            cin.ignore();
            getline(cin,nombre);
            cout << "Introduzca su alias:" << endl;
            cin >> alias;
            cout << "Introduzca su contraseña: " << endl;
            cin >> clave;
            usuarioActivo = new Usuario(nombre, alias, clave);
            foroActivo->nuevoUsuario(usuarioActivo);
            cout << endl;
            break;}
        case 4:{
            // Login
            string alias;
            cout << "\nIntroduzca su alias: " << endl;
            cin >> alias;
            usuarioActivo = foroActivo->usuarioPorAlias(alias);
            if (usuarioActivo == NULL) {
                cout << "\nSu usuario no está registrado\n" << endl;
            } else {
                string clave;
                cout << "\nIntroduzca su contraseña: " << endl;
                cin >> clave;
                if (usuarioActivo->validarClave(clave)){
                    cout << "\nConectado correctamente\n" << endl;
                } else {
                    cout << "\nLa contraseña es incorrecta\n" << endl;
                    usuarioActivo = NULL;
                }
            }
            break;}
        case 5:{
            // Crear tema
            if (usuarioActivo==NULL){
                cout << "\nSu usario no está debidamente registrado para crear Temas\n" << endl;
            } else {
                string denominacion;
                cout << "\nIntroduzca la denominacion del tema" << endl;
                cin.ignore();
                getline(cin,denominacion);
                foroActivo->nuevoTema(denominacion);
                cout << endl;
            }
            break;}
        default:{
            cout << "\nIntroduce una opción correcta\n" << endl;
            break;}
        }
    }
}

void GestionForo::devolverTema(int tema){
    Tema temaActivo = foroActivo->verTema(tema);
    int eleccionTema = -1;
    while(eleccionTema!=0){
        cout << "********************************************************" << endl;
        cout << "\t\t\t" << temaActivo.getDenominacion() << "\t\t\t" << endl;
        cout << "********************************************************" << endl;
        if (usuarioActivo==NULL) cout << "\t\t\t\tUsuario: Invitado" << endl;
        else cout << "\t\t\t\tUsuario: " << usuarioActivo->getAlias() << endl;
        cout << endl;
        cout << "*** 1)\tNumero de Hilos                              ***" << endl;
        cout << "*** 2)\tVer Hilo                                     ***" << endl;
        cout << "*** 3)\tNuevo Hilo                                   ***" << endl;
        cout << "*** 4)\tNumero de Mensajes                           ***" << endl;
        cout << "*** 5)\tBuscar Hilos                                 ***" << endl;
        cout << "*** 0)\tVolver a Foro                                ***" << endl;
        cout << endl;
        cout << "********************************************************" << endl;
        cin >> eleccionTema;
        switch (eleccionTema){
        case 0:{
            // Volver a foro
            devolverForo();
            break;}
        case 1:{
            // Devolver el número de hilos en este Tema
            if (temaActivo.numHilos()==0){
                cout << "\nAún no han sido creados Hilos para este Tema\n" << endl;
            } else {
                cout << "\nEl número de Hilos actualmente es " << temaActivo.numHilos() << "\n" << endl;
            }
            break;}
        case 2:{
            // Ver Hilo
            int numHilo = -1;
            if (temaActivo.numHilos() > 0){
                cout << endl;
                int contador = 0;

                for(Hilo & item: *(temaActivo.getVectorHilos())){
                    cout << contador << "\t" << item.getTitulo() << endl;
                    contador++;
                }

                cout << "\nIntroduzca el número de Hilo que desea ver: " << endl;
                cin >> numHilo;
                if(numHilo>=0 && numHilo<temaActivo.getVectorHilos()->size()){
                    eleccionTema = -1;
                    temaTemp = &temaActivo;
                    this->devolverHilo(numHilo);
                    cout << endl;
                } else cout << "\nIntroduce un número de Hilo correcto\n" << endl;
            } else {
                cout << "\nAún no han sido creados Hilos para este Tema\n" << endl;
            }
            break;}
        case 3:{
            // Nuevo Hilo
            if (usuarioActivo==NULL) {
                cout << "\nNo está debidamente registrado\n" << endl;
            } else {
                string titulo, mensaje;
                cout << "\nIntroduzca el título del Hilo" << endl;
                cin.ignore();
                getline(cin,titulo);
                cout << "\nIntroduzca el mensaje inicial" << endl;
                getline(cin,mensaje);
                cout << endl;
                temaActivo.nuevoHilo(titulo,new Mensaje(usuarioActivo, mensaje));
            }
            break;}
        case 4:{
            // Número de mensajes
            cout << "\nEl número total de Mensajes en este Tema es " << temaActivo.numMensajes() << "\n" << endl;
            break;}
        case 5:{
            //buscar Hilos
            string termino;
            cout << "\nIntroduzca el termino a buscar" << endl;
            cin >> termino;
            cout << endl;
            vector<Hilo> *hilos = temaActivo.buscaHilos(termino);
            if(hilos->size()==0){
                cout << "\nNo hay Hilos que coincidan con dicho termino\n" << endl;
            } else {
                cout << "\nLos siguientes Hilos coinciden con el termino\n" << endl;
                for(Hilo & item: *hilos){
                    cout << "\t" << item.getTitulo() << endl;
                }
                cout << endl;
            }
            hilos->clear();
            break;}
        default:{
            cout << "\nIntroduce una opción correcta\n" << endl;
            break;}
        }
    }
}

void GestionForo::devolverHilo(int hilo){
    Hilo hiloActivo = temaTemp->verHilo(hilo);
    int eleccionHilo = -1;
    while(eleccionHilo!=0){
        cout << "********************************************************" << endl;
        cout << "\t\t\t" << hiloActivo.getTitulo() << "\t\t\t" << endl;
        cout << "********************************************************" << endl;
        if (usuarioActivo==NULL) cout << "\t\t\t\tUsuario: Invitado" << endl;
        else cout << "\t\t\t\tUsuario: " << usuarioActivo->getAlias() << endl;
        cout << endl;
        cout << "*** 1)\tNuevo Mensaje                                ***" << endl;
        cout << "*** 2)\tNumero de Mensajes                           ***" << endl;
        cout << "*** 3)\tVer Mensaje                                  ***" << endl;
        cout << "***                                                  ***" << endl;
        cout << "*** 4)\tMostrar todos los Mensajes                   ***" << endl;
        cout << "*** 0)\tVolver a Tema                                ***" << endl;
        cout << endl;
        cout << "********************************************************" << endl;
        cin >> eleccionHilo;
        switch (eleccionHilo){
        case 0:{
            //Volver a Tema
            devolverTema(numTemp);
            break;}
        case 1:{
            //Nuevo Mensaje
            if (usuarioActivo == NULL){
                cout << "\nNo está registrado\n" << endl;
            } else {
                string mensaje;
                cout << "\nIntroduzca el mensaje" << endl;
                cin.ignore();
                getline(cin,mensaje);
                hiloActivo.nuevoMensaje(mensaje, usuarioActivo);
                cout << "\nMensaje guardado con éxito\n" << endl;
            }
            break;}
        case 2:{
            //Numero de mensajes
            cout << "\nEl número de mensajes del actual hilo es " << hiloActivo.numeroMensajes() << "\n" << endl;
            break;}
        case 3:{
            //Ver Mensaje
            int numMensaje;
            cout << "\nIntroduzca el número de mensaje que desee ver" << endl;
            cin >> numMensaje;
            if (numMensaje<0 || numMensaje>=hiloActivo.getVectorMensajes().size()){
                cout << "\nNo se puede acceder a ese número de Mensaje\n" << endl;
            } else {
                Mensaje mensaje = hiloActivo.verMensaje(numMensaje);
                cout << "\n" << mensaje.verAutor()->getAlias() << " :: " << mensaje.getFecha()->getFecha() << " :: " << mensaje.getContenido() << "\n" << endl;
            }
            break;}
        case 4:{
            //Mostrar todos los Mensajes
            for(Mensaje & item : hiloActivo.getVectorMensajes()){
                cout << item.verAutor()->getAlias() << " :: " << item.getFecha()->getFecha() << " :: " << item.getContenido() << endl;
            }
            cout << endl;
            break;}
        default:{
            cout << "\nIntroduzca una opción correcta\n" << endl;
            break;}
        }

    }
}
