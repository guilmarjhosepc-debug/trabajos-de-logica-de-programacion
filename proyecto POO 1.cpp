#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Funciones de texto ----------
bool esEspacio(char c) { return c == ' ' || c == '\t' || c == '\r' || c == '\n'; }

string quitarEspacios(string texto) {
    int inicio = 0, fin = texto.size() - 1;
    while (inicio <= fin && esEspacio(texto[inicio])) inicio++;
    while (fin >= inicio && esEspacio(texto[fin])) fin--;
    return texto.substr(inicio, fin - inicio + 1);
}

string aMinusculas(string texto) {
    for (int i = 0; i < texto.size(); i++) texto[i] = tolower(texto[i]);
    return texto;
}

bool contiene(string texto, string parte) {
    return aMinusculas(texto).find(aMinusculas(parte)) != string::npos;
}

bool esSoloDigitos(string texto) {
    for (int i = 0; i < texto.size(); i++) {
        if (texto[i] < '0' || texto[i] > '9') return false;
    }
    return !texto.empty();
}

// ---------- Lectura de datos ----------
void terminarPrograma() {
    cout << "\nEntrada finalizada\n";
    exit(0);
}

string leerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    if (!getline(cin, texto)) terminarPrograma();
    return quitarEspacios(texto);
}

string leerTextoObligatorio(string mensaje) {
    string texto = leerTexto(mensaje);
    while (texto == "") texto = leerTexto("Este dato es obligatorio: ");
    return texto;
}

int leerEntero(string mensaje) {
    int numero;
    cout << mensaje;
    while (!(cin >> numero)) {
        if (cin.eof()) terminarPrograma();
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Debe ingresar un numero entero: ";
    }
    cin.ignore(1000, '\n');
    return numero;
}

vector<string> leerNumeros() {
    int cantidad = leerEntero("Cuantos numeros desea guardar (1 a 5)? ");
    while (cantidad < 1 || cantidad > 5) cantidad = leerEntero("Debe ser entre 1 y 5: ");
    vector<string> numeros;
    for (int i = 1; i <= cantidad; i++) {
        string numero = leerTexto("Numero " + to_string(i) + ": ");
        while (!esSoloDigitos(numero)) numero = leerTexto("Solo digitos, intente de nuevo: ");
        numeros.push_back(numero);
    }
    return numeros;
}

// ---------- Clase Fecha ----------
class Fecha {
private:
    int dia, mes, ano;
public:
    Fecha() { dia = 1; mes = 1; ano = 2000; }
    Fecha(int d, int m, int a) { dia = d; mes = m; ano = a; }
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAno() { return ano; }

    // static: se usa sin crear una Fecha -> Fecha::hoy()
    static Fecha hoy() {
        time_t ahora = time(0);
        tm* local = localtime(&ahora);
        return Fecha(local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
    }

    bool esValida() {
        int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        Fecha actual = hoy();
        if (ano < 1900 || ano > actual.ano || mes < 1 || mes > 12 || dia < 1) return false;
        bool bisiesto = (ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0;
        if (mes == 2 && bisiesto) return dia <= 29;
        return dia <= diasPorMes[mes - 1];
    }

    void imprimir() {
        if (dia < 10) cout << "0";
        cout << dia << "/";
        if (mes < 10) cout << "0";
        cout << mes << "/" << ano;
    }
};

Fecha leerFecha() {
    while (true) {
        int d = leerEntero("Dia de nacimiento: ");
        int m = leerEntero("Mes de nacimiento: ");
        int a = leerEntero("Ano de nacimiento: ");
        Fecha fecha(d, m, a);
        if (fecha.esValida()) return fecha;
        cout << "La fecha no es valida, intente de nuevo\n";
    }
}

// ---------- Clases de Contacto ----------
// Clase base abstracta: las funciones "= 0" las definen las clases hijas
class Contacto {
private:
    vector<string> numeros;
    string nombre, correo, direccion, extra;   // extra = relacion o empresa
    bool estaBloqueado, eliminado;
    Fecha fechaNacimiento;
public:
    Contacto(vector<string> nums, string nom, string cor, string dir, Fecha fecha, string ext) {
        numeros = nums; nombre = nom; correo = cor; direccion = dir;
        fechaNacimiento = fecha; extra = ext;
        estaBloqueado = false; eliminado = false;
    }
    virtual ~Contacto() {}
    virtual string tipo() = 0;
    virtual string nombreExtra() = 0;
    virtual void mostrarExtra() = 0;

    vector<string> getNumeros() { return numeros; }
    string getNombre() { return nombre; }
    string getCorreo() { return correo; }
    string getDireccion() { return direccion; }
    string getExtra() { return extra; }
    bool getEstaBloqueado() { return estaBloqueado; }
    bool getEliminado() { return eliminado; }
    Fecha getFechaNacimiento() { return fechaNacimiento; }

    void setNumeros(vector<string> nums) { numeros = nums; }
    void setNombre(string nom) { nombre = nom; }
    void setCorreo(string cor) { correo = cor; }
    void setDireccion(string dir) { direccion = dir; }
    void setExtra(string ext) { extra = ext; }
    void setFechaNacimiento(Fecha fecha) { fechaNacimiento = fecha; }
    void bloquear() { estaBloqueado = true; }
    void desbloquear() { estaBloqueado = false; }
    void eliminar() { eliminado = true; }

    string numerosComoTexto() {
        string resultado = "";
        for (int i = 0; i < numeros.size(); i++) {
            resultado = resultado + numeros[i];
            if (i + 1 < numeros.size()) resultado = resultado + ", ";
        }
        return resultado;
    }

    int calcularEdad(Fecha hoy) {
        int edad = hoy.getAno() - fechaNacimiento.getAno();
        if (hoy.getMes() < fechaNacimiento.getMes()) edad--;
        else if (hoy.getMes() == fechaNacimiento.getMes() && hoy.getDia() < fechaNacimiento.getDia()) edad--;
        return edad;
    }

    bool cumpleHoy(Fecha hoy) {
        return hoy.getDia() == fechaNacimiento.getDia() && hoy.getMes() == fechaNacimiento.getMes();
    }

    void mostrar() {
        cout << " Nombre     : " << nombre << "\n";
        cout << " Correo     : " << correo << "\n";
        cout << " Direccion  : " << direccion << "\n";
        cout << " Numeros    : " << numerosComoTexto() << "\n";
        cout << " Nacimiento : ";
        fechaNacimiento.imprimir();
        cout << "\n Edad       : " << calcularEdad(Fecha::hoy()) << " anos\n";
        mostrarExtra();
    }
};

class ContactoPersonal : public Contacto {
public:
    ContactoPersonal(vector<string> nums, string nom, string cor, string dir, Fecha fecha, string rel)
        : Contacto(nums, nom, cor, dir, fecha, rel) {}
    string tipo() { return "Personal"; }
    string nombreExtra() { return "Relacion"; }
    void mostrarExtra() { cout << " Relacion   : " << getExtra() << "\n"; }
};

class ContactoTrabajo : public Contacto {
public:
    ContactoTrabajo(vector<string> nums, string nom, string cor, string dir, Fecha fecha, string emp)
        : Contacto(nums, nom, cor, dir, fecha, emp) {}
    string tipo() { return "Trabajo"; }
    string nombreExtra() { return "Empresa"; }
    void mostrarExtra() { cout << " Empresa    : " << getExtra() << "\n"; }
};

// ---------- Clases de Busqueda ----------
class Buscador {
public:
    virtual ~Buscador() {}
    virtual bool coincide(Contacto* contacto, string texto) = 0;
};

class BuscadorNombre : public Buscador {
public:
    bool coincide(Contacto* c, string texto) { return contiene(c->getNombre(), texto); }
};

class BuscadorNumero : public Buscador {
public:
    bool coincide(Contacto* c, string texto) {
        vector<string> numeros = c->getNumeros();
        for (int i = 0; i < numeros.size(); i++) {
            if (numeros[i].find(texto) != string::npos) return true;
        }
        return false;
    }
};

class BuscadorCorreo : public Buscador {
public:
    bool coincide(Contacto* c, string texto) { return contiene(c->getCorreo(), texto); }
};

class BuscadorDireccion : public Buscador {
public:
    bool coincide(Contacto* c, string texto) { return contiene(c->getDireccion(), texto); }
};

// ---------- Clase Agenda ----------
class Agenda {
private:
    vector<Contacto*> contactos;
public:
    ~Agenda() {
        for (int i = 0; i < contactos.size(); i++) delete contactos[i];
    }

    void registrar(Contacto* contacto) { contactos.push_back(contacto); }

    // Contactos que no han sido eliminados
    vector<Contacto*> obtenerVisibles() {
        vector<Contacto*> visibles;
        for (int i = 0; i < contactos.size(); i++) {
            if (!contactos[i]->getEliminado()) visibles.push_back(contactos[i]);
        }
        return visibles;
    }

    vector<Contacto*> buscar(Buscador& buscador, string texto) {
        vector<Contacto*> visibles = obtenerVisibles();
        vector<Contacto*> resultado;
        for (int i = 0; i < visibles.size(); i++) {
            if (buscador.coincide(visibles[i], texto)) resultado.push_back(visibles[i]);
        }
        return resultado;
    }

    vector<Contacto*> cumpleanosHoy() {
        vector<Contacto*> visibles = obtenerVisibles();
        vector<Contacto*> resultado;
        for (int i = 0; i < visibles.size(); i++) {
            if (visibles[i]->cumpleHoy(Fecha::hoy())) resultado.push_back(visibles[i]);
        }
        return resultado;
    }
};

// ---------- Pantalla y seleccion ----------
void mostrarLista(vector<Contacto*> lista) {
    for (int i = 0; i < lista.size(); i++) {
        string estado = "Activo";
        if (lista[i]->getEstaBloqueado()) estado = "Bloqueado";
        cout << "====================================================\n";
        cout << " CONTACTO " << i + 1 << "  |  " << lista[i]->tipo() << "  |  " << estado << "\n";
        cout << "----------------------------------------------------\n";
        lista[i]->mostrar();
    }
    cout << "====================================================\n";
}

// Elige un contacto por posicion, telefono o nombre. Devuelve nullptr si se cancela.
Contacto* elegirContacto(Agenda& agenda) {
    vector<Contacto*> opciones = agenda.obtenerVisibles();
    if (opciones.empty()) {
        cout << "\n-> No hay contactos registrados.\n";
        return nullptr;
    }
    BuscadorNombre porNombre;
    BuscadorNumero porNumero;
    while (true) {
        mostrarLista(opciones);
        string texto = leerTextoObligatorio("Numero de la lista, telefono o nombre (0 para cancelar): ");
        if (texto == "0") return nullptr;

        int indice = 0;
        if (esSoloDigitos(texto) && texto.size() < 4) indice = stoi(texto);
        if (indice >= 1 && indice <= opciones.size()) return opciones[indice - 1];

        vector<Contacto*> encontrados;
        for (int i = 0; i < opciones.size(); i++) {
            if (porNombre.coincide(opciones[i], texto) || porNumero.coincide(opciones[i], texto)) {
                encontrados.push_back(opciones[i]);
            }
        }
        if (encontrados.size() == 1) return encontrados[0];
        if (encontrados.empty()) {
            cout << "\n-> No se encontro ningun contacto con \"" << texto << "\", intente de nuevo.\n";
        } else {
            cout << "\n-> Hay " << encontrados.size() << " contactos que coinciden, elija uno de esta lista.\n";
            opciones = encontrados;
        }
    }
}

// ---------- Opciones del menu ----------
void registrarContacto(Agenda& agenda) {
    cout << "--- REGISTRAR CONTACTO ---\n";
    int tipo = leerEntero("Tipo de contacto (1 Personal, 2 Trabajo): ");
    if (tipo != 1 && tipo != 2) {
        cout << "\n-> Tipo de contacto no valido.\n";
        return;
    }
    string nom = leerTextoObligatorio("Nombre: ");
    string cor = leerTexto("Correo: ");
    string dir = leerTexto("Direccion: ");
    vector<string> nums = leerNumeros();
    Fecha fecha = leerFecha();
    if (tipo == 1) {
        string rel = leerTexto("Relacion: ");
        agenda.registrar(new ContactoPersonal(nums, nom, cor, dir, fecha, rel));
    } else {
        string emp = leerTexto("Empresa: ");
        agenda.registrar(new ContactoTrabajo(nums, nom, cor, dir, fecha, emp));
    }
    cout << "\n-> Contacto registrado con exito!\n\n";
}

// Muestra el valor actual y pide uno nuevo (vacio = cancelar)
string pedirNuevoValor(string actual) {
    cout << " Valor actual: " << actual << "\n";
    return leerTexto(" Nuevo valor (Enter para cancelar): ");
}

void editarContacto(Agenda& agenda) {
    cout << "--- EDITAR CONTACTO ---\n";
    Contacto* contacto = elegirContacto(agenda);
    if (contacto == nullptr) return;

    bool huboCambios = false;
    int opcion = -1;
    while (opcion != 0) {
        cout << "\n====================================================\n";
        cout << " EDITAR CONTACTO: " << contacto->getNombre() << "\n";
        cout << "----------------------------------------------------\n";
        cout << " 1) Nombre\n 2) Correo electronico\n 3) Direccion\n";
        cout << " 4) Numeros de telefono\n 5) Fecha de nacimiento\n";
        cout << " 6) " << contacto->nombreExtra() << "\n 0) Terminar edicion\n";
        cout << "====================================================\n";
        opcion = leerEntero("Que desea editar: ");

        bool cambio = false;
        string valor = "";
        if (opcion == 1) {
            valor = pedirNuevoValor(contacto->getNombre());
            if (valor != "") { contacto->setNombre(valor); cambio = true; }
        } else if (opcion == 2) {
            valor = pedirNuevoValor(contacto->getCorreo());
            if (valor != "") { contacto->setCorreo(valor); cambio = true; }
        } else if (opcion == 3) {
            valor = pedirNuevoValor(contacto->getDireccion());
            if (valor != "") { contacto->setDireccion(valor); cambio = true; }
        } else if (opcion == 6) {
            valor = pedirNuevoValor(contacto->getExtra());
            if (valor != "") { contacto->setExtra(valor); cambio = true; }
        } else if (opcion == 4) {
            cout << " Numeros actuales: " << contacto->numerosComoTexto() << "\n";
            if (leerEntero(" Reemplazar los numeros? (1 Si, 2 No): ") == 1) {
                contacto->setNumeros(leerNumeros());
                cambio = true;
            }
        } else if (opcion == 5) {
            cout << " Nacimiento actual: ";
            contacto->getFechaNacimiento().imprimir();
            cout << "\n";
            contacto->setFechaNacimiento(leerFecha());
            cambio = true;
        } else if (opcion != 0) {
            cout << "\n-> Opcion invalida, elija un numero del 0 al 6.\n";
        }

        if (cambio) {
            cout << "\n-> Dato actualizado!\n";
            huboCambios = true;
        }
    }

    if (huboCambios) {
        cout << "\n-> Contacto actualizado con exito, estos son sus datos:\n";
        vector<Contacto*> unico;
        unico.push_back(contacto);
        mostrarLista(unico);
    } else {
        cout << "\n-> No se realizaron cambios.\n";
    }
}

void eliminarContacto(Agenda& agenda) {
    cout << "--- ELIMINAR CONTACTO ---\n";
    Contacto* contacto = elegirContacto(agenda);
    if (contacto == nullptr) return;
    contacto->eliminar();
    cout << "\n-> Contacto eliminado correctamente!\n";
}

void bloquearContacto(Agenda& agenda) {
    cout << "--- BLOQUEAR / DESBLOQUEAR ---\n";
    Contacto* contacto = elegirContacto(agenda);
    if (contacto == nullptr) return;
    if (contacto->getEstaBloqueado()) {
        contacto->desbloquear();
        cout << "\n-> El contacto ha sido DESBLOQUEADO.\n";
    } else {
        contacto->bloquear();
        cout << "\n-> El contacto ha sido BLOQUEADO.\n";
    }
}

void buscarContacto(Agenda& agenda) {
    cout << "--- BUSCAR CONTACTO ---\n";
    int criterio = leerEntero("Buscar por (1 Nombre, 2 Numero, 3 Correo, 4 Direccion): ");
    BuscadorNombre porNombre;
    BuscadorNumero porNumero;
    BuscadorCorreo porCorreo;
    BuscadorDireccion porDireccion;
    Buscador* buscador = &porNombre;
    if (criterio == 2) buscador = &porNumero;
    else if (criterio == 3) buscador = &porCorreo;
    else if (criterio == 4) buscador = &porDireccion;
    else if (criterio != 1) {
        cout << "\n-> Criterio de busqueda no valido.\n";
        return;
    }
    string texto = leerTextoObligatorio("Texto a buscar: ");
    vector<Contacto*> resultado = agenda.buscar(*buscador, texto);
    if (resultado.empty()) {
        cout << "\n-> Contacto no encontrado.\n";
        return;
    }
    cout << "\n--- INFORMACION ENCONTRADA ---\n";
    mostrarLista(resultado);
}

// ---------- Programa principal ----------
int main() {
    system("color 0a");
    Agenda agenda;
    int opcion = -1;
    while (opcion != 0) {
        system("cls");
        cout << "========== AGENDA UNIVERSITARIA ==========\n";
        cout << "1) Registrar nuevo contacto\n2) Editar contacto\n3) Listar contactos\n";
        cout << "4) Eliminar contacto\n5) Bloquear/Desbloquear contacto\n";
        cout << "6) Buscar contacto\n7) Cumpleanos de hoy\n0) Salir\n";
        cout << "==========================================\n";
        opcion = leerEntero("Seleccione una opcion: ");
        system("cls");

        if (opcion == 1) registrarContacto(agenda);
        else if (opcion == 2) editarContacto(agenda);
        else if (opcion == 3) {
            cout << "==========================================\n";
            cout << "            LISTA DE CONTACTOS            \n";
            cout << "==========================================\n";
            vector<Contacto*> lista = agenda.obtenerVisibles();
            if (lista.empty()) cout << "\nNo hay contactos guardados o activos.\n";
            else mostrarLista(lista);
        }
        else if (opcion == 4) eliminarContacto(agenda);
        else if (opcion == 5) bloquearContacto(agenda);
        else if (opcion == 6) buscarContacto(agenda);
        else if (opcion == 7) {
            cout << "--- CUMPLEANOS DE HOY ---\n";
            vector<Contacto*> lista = agenda.cumpleanosHoy();
            if (lista.empty()) cout << "\nNadie cumple anos hoy.\n";
            else mostrarLista(lista);
        }
        else if (opcion == 0) {
            cout << "Saliendo de la agenda... Hasta luego!\n";
            continue;   // al salir no hace falta la pausa
        }
        else cout << "Opcion no valida. Intente de nuevo.\n\n";

        system("pause");   // una sola pausa para todas las opciones
    }
    return 0;
}
