#include <mysql.h>
#include <iostream>
using namespace std;
int q_estado;
int main()
{

    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* Resultado;

    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "4716", "db_kardex", 3306, NULL, 0);
    if (conectar) {
        //cout << "conexion Exitosa..." << endl;
        string puesto;
        cout << "Ingrese Puesto:";
        cin >> puesto;
        string insert = "insert into proveedores(proveedores) values('" + puesto + "')";
        const char* i = insert.c_str();
        q_estado = mysql_query(conectar, i);
        if (!q_estado) {
        
            cout << "Ingreso Exitoso..." << endl;
        
        }
        

        string consulta = "select * from puestos";
        const char* c = consulta.c_str();
        q_estado = mysql_query(conectar, c);
        if (!q_estado) {
            resultado = mysql_store_result(conectar);
            while(fila = mysql_fetch_row(resultado) ){
                cout << fila[0] << "," << fila[1] << endl;
            
            }
            cout << "Ingreso Exitoso..." << endl;
        }
    }
    else {
        cout << " xxxxx Error al ingresar xxxxx" << endl;
    
    }

    system("pause");
    return 0;
}


