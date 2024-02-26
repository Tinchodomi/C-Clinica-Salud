////////////////////////////// Librerias C++ ///////////////////////////////
#include<iostream>
#include<string>
#include<cstdio>
#include<stdlib.h> 


using namespace std;


///////////////////////// ESTRUCTURAS DE DATOS //////////////////////////////


struct Especilidad_medica
{
    int codigo;
    string nombre;
    string descripcion;
};

struct Paciente
{
    string apellido;
    string nombre;
    int dni;
    long telefono;

};

struct Turno
{
    int codigo;
    string fecha;
    string hora;
    int paciente;
    int especialidades_medicas;
    int estado;
};


/////////////////////////LISTAS/////////////////////////

const int DF = 10; ///dimension fisica

Especilidad_medica especialidad_medica[DF];
int dl_em = 0; //dimension logica especialidades medicas

Paciente paciente[DF]; 
int dlp = 0; ///dimension logica pacientes

Turno turnos[DF];
Turno cancelados[DF];
int dlt = 0;   ///dimension logica turnos
int dltc = 0; ///dimension logica de turnos cancelados

//////////////////////////////PROTOTIPOS DE LAS FUNCIONES////////////////////

void Menu(), Bienvenida(), System(); 
void Submenu_Especialidades_medicas(), Submenu_paciente(), Submenu_turno();
void Submenu_listados_pacientes(), Submenu_listados_Especialidaes_medicas();
void Submenu_listados_turnos(),turnos_activos(),turnos_cancelados(),busqueda_por_paciente();
void busqueda_por_especialidad();

/////////////////////////ESPECIALIDADES MEDICAS////////////////////////////////

void Alta_Especialidades_medicas(void){

   
    fflush(stdin); 
    cout << "Ingrese Especialidad:";
    getline(cin,especialidad_medica[dl_em].nombre);
    

    cout << "Ingrese Descripcion (opcional):";
    getline(cin,especialidad_medica[dl_em].descripcion);
    
    especialidad_medica[dl_em].codigo = dl_em; 
    //empezamos el codigo en 0 que aumenta en 1 a medida que lo hace la dl_em;
        cout << "Especialidad cargada al sistema" <<endl;
        cout <<"------------------------------" <<endl;
        cout << "Especialidad:" << especialidad_medica[dl_em].nombre <<endl;
        cout << "Descripcion:" << especialidad_medica[dl_em].descripcion <<endl;
        cout << "Codigo:" << especialidad_medica[dl_em].codigo <<endl;
        cout <<"------------------------------" <<endl;
        dl_em++;


    
    System();
    cout << endl;
    
}

void Modif_Especialidades_medicas(void){
    
    int i = 0;
    int modificar_em;
    
    cout << "Ingrese el CODGIO de la Especialidad Medica que desea modificar:";
    cin >> modificar_em;

        
    while (i < dl_em && especialidad_medica[i].codigo != modificar_em)
    {
        i++;

    }    
    if (especialidad_medica[i].codigo == modificar_em) 
    {    
            fflush(stdin);
            cout << "Ingrese Especialidad:";
            getline(cin,especialidad_medica[i].nombre);
            cout << "Ingrese Descripcion:";
            getline(cin,especialidad_medica[i].descripcion);
            cout << "Especialidad Medica modificada con exito"<< endl;
           
    }else
    {
        cout << "No se encontro el CODIGO requerido" << endl; 
    }        



    System();
    cout << endl;    
}

void Baja_Especialidades_medicas(void){

    
    int i = 0;
    int eliminar_em;
    cout << "Ingrese el CODIGO de la Especialidad medica que desea eliminar:";
    cin >> eliminar_em;


    while (i < dl_em && especialidad_medica[i].codigo != eliminar_em)
    {
        i++;
    }
    
    if (especialidad_medica[i].codigo == eliminar_em)
    {   

        if (especialidad_medica[i].codigo == turnos[i].especialidades_medicas && turnos[i].estado == 1)
        {
           cout<<"La especialidad médica no puede eliminarse debido a que se encuentra presente enuno o más turnos reservados";
        }
        else{
        int opcion_elim; 
        cout <<"La especialidad medica a eliminar es:" <<endl;
        cout <<"------------------------------" <<endl;
        cout<< "Especilidad:" << especialidad_medica[i].nombre <<endl;
        cout<< "Descripcion:" << especialidad_medica[i].descripcion <<endl;
        cout<< "Codigo:" << especialidad_medica[i].codigo<<endl;
        cout <<"------------------------------" <<endl;
        cout<<"Esta seguro que desea eliminarlo(1.Si/2.No):";
        cin >> opcion_elim;
        if (opcion_elim == 1)
        {
          for (int j = i; j < dl_em-1; j++)
        {
            especialidad_medica[j] = especialidad_medica[j+1];  
        }

            dl_em--;
            cout<<"Especialidad medica eliminada" <<endl;
 
        }
        }     
    }else
    {
        cout << "No posee Especialidades Medicas con ese CODIGO" << endl;
    }

     for ( int i = 0; i < dl_em; i++)
    {
        especialidad_medica[i].codigo --;
    }

    System();
    


    System();
    cout << endl; 
    
    
}

void Listado_Especialidades_medicas(void){

    system("clear");
    cout << "LISTADO COMPLETO DE ESPECIALIDADES MEDICAS:" << endl;
    
    for ( int i = 0; i < dl_em; i++)
    {
        cout <<"------------------------------" <<endl;
        cout<< "Especilidad:" << especialidad_medica[i].nombre <<endl;
        cout<< "Descripcion:" << especialidad_medica[i].descripcion <<endl;
        cout<< "Codigo:" << especialidad_medica[i].codigo<<endl;
        cout <<"------------------------------" <<endl;
        cout << endl <<endl;
    }

    System();
    
}

void Busqueda_Especialidades_medicas(void){

        system("clear");
        int busqueda_codigo;
        int i = 0;
        cout <<"Ingrese CODIGO de la especialidad:";
        cin >> busqueda_codigo;

        while (i < dl_em && especialidad_medica[i].codigo != busqueda_codigo)
        {
        i++;

        } 

        if (especialidad_medica[i].codigo == busqueda_codigo)
        {
            
            cout<< "Especilidad:" << especialidad_medica[i].nombre <<endl;
            cout<< "Descripcion:" << especialidad_medica[i].descripcion <<endl;
            cout<< "Codigo:" << especialidad_medica[i].codigo<<endl;
            cout << endl <<endl;
        }else
        {
            cout <<"No existe Especialidad medica con ese codigo" <<endl;
        }
        
         
        
    System();
}


//////////////////////////////PACIENTES/////////////////////////////////

void Alta_paciente(void){

    cout << "-------------------- Alta de pacientes ------------------" <<endl;
    int dni_paciente;
    int i = 0;
    cout << "Ingrese DNI:";
    cin >> dni_paciente;

    while (i < dlp && paciente[i].dni != dni_paciente)
    {
        i++;
    }

    if (paciente[i].dni == dni_paciente){

        cout << "El ususario/DNI ya existe en el sistema" << endl;
    

    }else
    {   

        paciente[dlp].dni = dni_paciente;
        fflush(stdin);
        cout << "Ingrese Nombre:";
        getline(cin,paciente[dlp].nombre);
        cout << "Ingrese Apellido:";
        getline(cin,paciente[dlp].apellido);
        cout << "Telefono:";
        cin >> paciente[dlp].telefono;
        cout << endl <<endl;
        cout << "Paciente cargado al sistema" <<endl;
        cout <<"------------------------------" <<endl;
        cout <<"Nombre:" << paciente[dlp].nombre <<endl;
        cout <<"Apellido:" << paciente[dlp].apellido <<endl;
        cout << "DNI:"<<paciente[dlp].dni <<endl;
        cout <<"Telefono:"<< paciente[dlp].telefono <<endl;
        cout <<"------------------------------" <<endl; 
        dlp++;   
    }    

    System();
    cout << endl;          
}

void Modif_paciente(void){

    int i = 0;
    int modificar_pac;
    cout << "Ingrese el DNI del paciente que desea modificar:";
    cin >> modificar_pac;

    while (i < dlp && paciente[i].dni != modificar_pac)
    {
        i++;
    }
    
    if (paciente[i].dni == modificar_pac)
    {    
            fflush(stdin);
            cout << "Ingrese Nombre:";
            getline(cin,paciente[i].nombre);
            cout << "Ingrese Apellido:";
            getline(cin,paciente[i].apellido);
            cout << "Telefono:";
            cin >> paciente[i].telefono; 

            cout << "Paciente modificado con exito" <<endl;
            cout <<"------------------------------" <<endl;
            cout <<"Nombre:" << paciente[i].nombre <<endl;
            cout <<"Apellido:" << paciente[i].apellido <<endl;
            cout <<"Telefono:"<< paciente[i].telefono <<endl;
            cout <<"------------------------------" <<endl;  
    }else
    {
        cout << "No se encontro el DNI requerido" << endl;
    }
        
    System();
    cout << endl; 
    
}

void Baja_paciente(void){

    int i = 0;
    int eliminar_pac;
    cout << "Ingrese el DNI del paciente que desea eliminar:";
    cin >> eliminar_pac;

    while (i < dlp && paciente[i].dni != eliminar_pac)
    {
        i++;
    }
    
    if (paciente[i].dni == eliminar_pac)
    {    

        
        if (turnos[i].paciente == paciente[i].dni && turnos[i].estado == 1)
        {
            cout <<"El paciente no puede eliminarse debido a que aún posee uno o más turnos reservados"<<endl;
        }
        else{
        
            int opcion_elim;
            cout << endl;
            cout<<"El paciente a eliminar es:"<<endl;
            cout <<"------------------------------" <<endl;
            cout <<"Nombre:" << paciente[i].nombre <<endl;
            cout <<"Apellido:" << paciente[i].apellido <<endl;
            cout << "DNI:"<<paciente[i].dni <<endl;
            cout <<"Telefono:"<< paciente[i].telefono <<endl;
            cout <<"------------------------------" <<endl;
            cout<<"Esta seguro que desea eliminarlo(1.Si/2.No):";
            cin >> opcion_elim;
            
            if (opcion_elim == 1)
            {
                for (int j = i; j < dlp-1; j++)
                {
                    paciente[j] = paciente[j+1];  
                }

                cout << "Paciente eliminado del sistema" << endl;
                dlp--;
            }
        }
    }
    else
    {
        cout << "No se encontro el usuario/DNI requerido" << endl;
    }
    
   
    System();
    cout << endl;
        
}

void Listado_paciente(void){

    system("clear");
    cout << "LISTADO COMPLETO DE PACIENTES:" << endl;
    
    for (int i = 0; i < dlp; i++)
    {   
        cout <<"------------------------------" <<endl;
        cout <<"Nombre:" << paciente[i].nombre <<endl;
        cout <<"Apellido:" << paciente[i].apellido <<endl;
        cout << "DNI:"<<paciente[i].dni <<endl;
        cout <<"Telefono:"<< paciente[i].telefono <<endl;
        cout <<"------------------------------" <<endl;
        cout << endl << endl;
    }

    System();
    
}

void Busqueda_paciente(void){
        
        system("clear");
        int busqueda_dni;
        int i = 0;
        cout <<"Ingrese DNI del paciente:";
        cin >> busqueda_dni;

         while (i < dlp && paciente[i].dni != busqueda_dni)
        {
            i++;
        }
    
        if (paciente[i].dni == busqueda_dni)
        {    
            cout <<endl;
            
            cout <<"Nombre:" << paciente[i].nombre <<endl;
            cout <<"Apellido:" << paciente[i].apellido <<endl;
            cout << "DNI:"<<paciente[i].dni <<endl;
            cout <<"Telefono:"<< paciente[i].telefono <<endl;
            cout << endl << endl;
        }else
            {
                cout << "No se encontro el usuario/DNI requerido" <<endl;
                
            }
        
    System();

}


//////////////////////////////TURNOS//////////////////////////////////


void Alta_turno(void){
    
    int i = 0;
    int dni_paciente;
    
    cout <<"Ingrese DNI del paciente:";
    cin >> dni_paciente;
    
   
    while (i < dlp && paciente[i].dni != dni_paciente)
    {
        i++;
    }
    
    if (paciente[i].dni == dni_paciente)
    {
        
        turnos[dlt].paciente = dni_paciente;

        int codigo_em;
        cout <<"Ingrese CODIGO de la Especialidad Medica:";
        cin >> codigo_em;
        
        while (i< dl_em && especialidad_medica[i].codigo != codigo_em)
        {
            i++; 
        } 

        if (especialidad_medica[i].codigo == codigo_em) 
        {   
            
            if (paciente[i].dni == turnos[i].paciente && especialidad_medica[i].codigo == turnos[i].codigo && turnos[i].estado ==1)
            {
                cout << "El ususario/DNI ya posee un turno con la especialidad medica solicitada" <<endl;
            }
            else{
            
            string fecha_turno;
            string hora_turno;
            cout <<"Ingrese dia del turno (formato dd/mm/aa):";
            cin >> fecha_turno;
            cout <<"Ingrese hora del turno (formato 00:00 am/pm):" ;
            cin >> hora_turno;
            turnos[dlt].fecha = fecha_turno;
            turnos[dlt].hora = hora_turno;
            turnos[dlt].especialidades_medicas = codigo_em;
            turnos[dlt].codigo = dlt;
            turnos[dlt].estado = 1;    
            dlt++;
            cout << "Se genero su turno en el sistema"<<endl;
            }
        }
        else
        {
            cout << "No se encontro el CODIGO requerido" << endl; //si no lo encuentra el sistema vuelve al punto anterior
        }
    }
    else
    {
        cout << "No se encontro el DNI requerido" << endl;
        cout <<"Ingrese al sistema el paciente antes de requerir un turno" << endl;
    }          
      
    System();
    cout << endl; 
    
    
}

void Modif_turno(void){

    int i = 0;
    int dni_paciente;
    int modificar_turno;

    cout << "Ingrese  DNI del paciente a modificar:";
    cin >> dni_paciente;
    
    while (i < dlp && paciente[i].dni != dni_paciente)
    {
        i++;
    }    
    
    if (paciente[i].dni == dni_paciente)
    {    
        
        cout <<"Ingrese el CODIGO de turno a modificar:";
        cin >> modificar_turno;
        
        
        while (i < dlt && turnos[i].codigo != modificar_turno)
        {
        i++;
        }

        if (turnos[i].codigo == modificar_turno)
        {
            cout <<"------------------------------" <<endl;
            cout << "DNI:" << turnos[i].paciente << endl;
            cout << "Codigo de Especialidad:" << turnos[i].especialidades_medicas<<endl;
            cout << "Codigo de turno:" << turnos[i].codigo <<endl;
            cout << "Estado:" << turnos[i].estado <<endl;
            cout <<"Dia:" << turnos[i].fecha <<endl;
            cout <<"Hora:" << turnos[i].hora <<endl;
            cout <<"------------------------------" <<endl;
            cout <<"Modificar turno:" <<endl;
            cout <<"Dia:"; 
            cin >> turnos[i].fecha;
            cout <<"Hora:"; 
            cin >>  turnos[i].hora;
            cout<< "Turno modificado con exito"<<endl;
        }else
        {
            cout << "El paciente no posee turnos registrados";
        }
    }
    else
    {
        cout << "No se encontro el DNI requerido" << endl;
    }
    
    System();
    cout << endl;


}

void Baja_turno(void){


    int dni_paciente;
    int i = 0;
    cout << "Ingrese el DNI del paciente para cancelar el turno:";
    cin >> dni_paciente;

    while (i < dlp && paciente[i].dni != dni_paciente)
    {
        i++;
    }

    if (paciente[i].dni == dni_paciente && turnos[i].estado == 0){

        cout<<"No existen turnos reservados con ese DNI"<<endl;

    }
    else
    {
        
        int eliminar_tur;
        int i = 0;
        cout << "Ingrese el CODIDO del turno que desea eliminar:";
        cin >> eliminar_tur;
    
        while (i < dlt && turnos[i].codigo != eliminar_tur)
        {
            i++;
        }
        
        if (turnos[i].codigo == eliminar_tur)
        {    
            int opcion_elim;
            cout<<"Turno a cancerlar:"<<endl;
            cout <<"------------------------------" <<endl;
            cout << "DNI:" << turnos[i].paciente << endl;
            cout << "Codigo de Especialidad:" << turnos[i].especialidades_medicas<<endl;
            cout << "Codigo de turno:" << turnos[i].codigo <<endl;
            cout << "Estado:" << turnos[i].estado <<endl;
            cout <<"Dia:" << turnos[i].fecha <<endl;
            cout <<"Hora:" << turnos[i].hora <<endl;
            cout <<"------------------------------" <<endl;

            cout<<"Esta seguro que desea cancelarlo(1.Si/2.No):";
            cin >> opcion_elim;
            
            if (opcion_elim == 1)
            {
                turnos[i].estado = 2;
                cancelados[dltc].paciente = turnos[i].paciente;
                cancelados[dltc].especialidades_medicas = turnos[i].especialidades_medicas;
                cancelados[dltc].codigo = turnos[i].codigo ;
                cancelados[dltc].estado = turnos[i].estado;
                cancelados[dltc].fecha = turnos[i].fecha;
                cancelados[dltc].hora = turnos[i].hora ;
                dltc++;

                for (int j = i; j < dlt-1; j++)
                {
                    turnos[j] = turnos[j+1];  
                }
                cout<<"Turno cancelado con exito"<<endl;
            }
        
            dlt--;
        
        }
        else
        {
            cout << "No existen turnos con ese CODIGO" << endl;
        }
    }

    System();
}

void Listado_turno(void){


    cout << endl;
    cout << "LISTADO COMPLETO DE TURNOS:" << endl;
    for (int i = 0; i < dlt; i++)
    {   
        
        cout <<"------------------------------" <<endl;
        cout << "DNI:" << turnos[i].paciente << endl;
        cout << "Codigo de Especialidad:" << turnos[i].especialidades_medicas<<endl;
        cout << "Codigo de turno:" << turnos[i].codigo <<endl;
        cout << "Estado:" << turnos[i].estado <<endl;
        cout <<"Dia:" << turnos[i].fecha <<endl;
        cout <<"Hora:" << turnos[i].hora <<endl;
        cout <<"------------------------------" <<endl;
        cout <<endl <<endl;
    }

    System();
}

void Busqueda_turno(void){

    system("clear");
    Bienvenida();
    cout << "--------------------------- Turnos ------------------------------" <<endl;
	cout << "1.Activos" <<endl;
    cout << "2.Cancelados" <<endl;
	cout << "3.Por Pacientes" <<endl;
	cout << "4.Por Fecha de Turno" <<endl;
	cout << "5.Por Especialidad" <<endl;
	cout << "Seleccione opción: ";
    char seleccione_opcion;
	cin >> seleccione_opcion;

    switch (seleccione_opcion)
    {
	case '1':
        turnos_activos();
		break;
	case '2':
        turnos_cancelados();
		break;
	case '3':
        busqueda_por_paciente();
		break;
	case '4':

        break;
     case '5':
        busqueda_por_especialidad();
        break;
	default:
        cout << "Seleccione una opcion valida" << endl;
        System();
		break;
    }

}

void turnos_activos(void){

    cout <<"TURNOS ACTIVOS"<< endl;
    for (int i = 0; i < dlt; i++)
    {   
        
        cout <<"------------------------------" <<endl;
        cout << "DNI:" << turnos[i].paciente << endl;
        cout << "Codigo de turno:" << turnos[i].codigo <<endl;
        cout << "Estado:" << turnos[i].estado <<endl;
        cout <<"Dia:" << turnos[i].fecha <<endl;
        cout <<"Hora:" << turnos[i].hora <<endl;
        cout <<"------------------------------" <<endl;
        cout <<endl <<endl;
    }

    System();

}

void turnos_cancelados(void){

    cout << endl;
    cout << "LISTADO COMPLETO DE TURNOS CANCELADOS:" << endl;
    
    for (int i = 0; i < dltc; i++)
    {   
        
        cout <<"------------------------------" <<endl;
        cout << "DNI:" << cancelados[i].paciente << endl;
        cout << "Codigo de Especialidad:" << cancelados[i].especialidades_medicas<<endl;
        cout << "Codigo de turno:" << cancelados[i].codigo <<endl;
        cout << "Estado:" << cancelados[i].estado <<endl;
        cout <<"Dia:" << cancelados[i].fecha <<endl;
        cout <<"Hora:" << cancelados[i].hora <<endl;
        cout <<"------------------------------" <<endl;
        cout <<endl <<endl;
    }

    System();

}

void busqueda_por_paciente(){

    int busqueda_dni;
    int i = 0;
    cout <<"Ingrese DNI del paciente:";
    cin >> busqueda_dni;

    while (i < dlt && turnos[i].paciente != busqueda_dni)
    {
        i++;
    }
    
    if (turnos[i].paciente == busqueda_dni)
    {    
        cout <<"------------------------------" <<endl;
        cout << "DNI:" << turnos[i].paciente << endl;
        cout << "Codigo de turno:" << turnos[i].codigo <<endl;
        cout << "Estado:" << turnos[i].estado <<endl;
        cout <<"Dia:" << turnos[i].fecha <<endl;
        cout <<"Hora:" << turnos[i].hora <<endl;
        cout <<"------------------------------" <<endl;

    }else{

        int i = 0;
         while (i < dltc && cancelados[i].paciente != busqueda_dni)
        {
            i++;
        }

        if (cancelados[i].paciente == busqueda_dni)
        {
              cout <<"------------------------------" <<endl;
            cout << "DNI:" << cancelados[i].paciente << endl;
            cout << "Codigo de Especialidad:" << cancelados[i].especialidades_medicas<<endl;
            cout << "Codigo de turno:" << cancelados[i].codigo <<endl;
            cout << "Estado:" << cancelados[i].estado <<endl;
            cout <<"Dia:" << cancelados[i].fecha <<endl;
            cout <<"Hora:" << cancelados[i].hora <<endl;
            cout <<"------------------------------" <<endl;
            cout <<endl <<endl;
        }
        


    }
    

   
    
    System();
}

void busqueda_por_especialidad(){

    int busqueda_codigo;
        int i = 0;
        cout <<"Ingrese CODIGO de la especialidad:";
        cin >> busqueda_codigo;

        while (i < dl_em && especialidad_medica[i].codigo != busqueda_codigo)
        {
        i++;

        } 

        if (especialidad_medica[i].codigo == busqueda_codigo)
        {
            
          
            
               
        }
        
    System();

}



//////////////////////////////////// MAIN ///////////////////////////////

int main(void){
    
    Menu();
}

void Bienvenida(void){
    cout << endl << endl;
	cout <<  "///////////////////////// Clínica Salud+ ///////////////////////////" <<endl;
    cout << endl << endl;
}

void System(void){
    
    cout << "Presione ENTER para continuar";
    fflush(stdin);
    cout << cin.get();
    system("clear");

}

void Menu(void){

    char menu;
    
    system("clear");
    do{
    Bienvenida();
    cout << endl;
    cout << "------------------------- Menu Principal -------------------------" <<endl;
    cout <<endl;
	cout << "1.Administrar Especialidades Médicas" <<endl;
	cout << "2.Administrar Pacientes" <<endl;
	cout << "3.Administrar Turnos" <<endl;
	cout << "4.Salir" <<endl;
	cout << "Seleccione opcion:";
	cin >> menu;
    cout << endl << endl;
	
    switch (menu)
	{
	case '1':
        system("clear"); 
		Submenu_Especialidades_medicas();
		break;
	case '2':
        system("clear");
        Submenu_paciente();
		break;
	case '3':
        system("clear");
        Submenu_turno();
		break;
	case '4': 
        system("clear");
        Bienvenida();
		cout << "Salio del Sistema Correctamente..." <<endl;
		break;
	default:
        cout << "Seleccione una opcion valida" << endl;
        System();
		break;
        
	}
    
    } while ( menu != '4');
}

void Submenu_Especialidades_medicas(void){
    
    char submenu_em;
   
    do{
    Bienvenida();
    cout << "-------------------- Especialidades Médicas ---------------------" <<endl << endl;
	cout << "a.Alta de Especialidades Médicas" <<endl;
	cout << "b.Modificación de Especialidades Médicas" <<endl;
	cout << "c.Baja de Especialidades Médicas" <<endl;
	cout << "d.Listado de Especialidades Médicas" <<endl;
    cout << "e.Menu Principal" <<endl;
	cout << "Seleccione opción: ";
	cin >> submenu_em;
    cout << endl << endl;
	
	switch (submenu_em)
	{
	case 'a':
        if (dl_em >= DF)
        {
            cout <<"Sin espacio en el arreglo" <<endl;
            System();
        }
        else{
		    Alta_Especialidades_medicas();
        }
		break;
	case 'b':
		    Modif_Especialidades_medicas();
		break;
	case 'c':
        Baja_Especialidades_medicas();
		break;
    case 'd':
        Submenu_listados_Especialidaes_medicas();
        break;
    case 'e':
        system("clear");
        break;
	default:
        cout << "Seleccione una opcion valida" <<endl;
        System();
		break;
	}

    } while (submenu_em != 'e');
    
}

void Submenu_paciente(void){
    
    
    char submenu_pac;

    do
    {
    Bienvenida();
    cout << "-------------------------- Pacientes ----------------------------" <<endl;
	cout << "a.Alta de Pacientes" <<endl;
	cout << "b.Modificación de Pacientes" <<endl;
	cout << "c.Baja de Pacientes" <<endl;
	cout << "d.Listado de Pacientes" <<endl;
    cout << "e.Menu Principal" <<endl;
	cout << "Seleccione opción: ";
	cin >> submenu_pac;
    cout << endl << endl;
	
	switch (submenu_pac)
	{
	case 'a':
         if (dlp >= DF)
        {
            cout <<"Sin espacio en el arreglo" <<endl;
            System();
        }
        else{
		    Alta_paciente();
        }
		break;
	case 'b':
		Modif_paciente();
		break;
	case 'c':
		Baja_paciente();
		break;
	case 'd': 
        Submenu_listados_pacientes();
        break;
    case 'e':
        system("clear");
        break;
	default:
        cout << "Seleccione una opcion valida" <<endl;
        System();
		break;
	}

    } while (submenu_pac != 'e');
}

void Submenu_turno(void){
   
    char submenu_tur;

    do
    {
    Bienvenida();
    cout << "--------------------------- Turnos ------------------------------" <<endl;
	cout << "a.Alta de Turnos" <<endl;
	cout << "b.Modificación de Turnos" <<endl;
	cout << "c.Baja de Turnos" <<endl;
	cout << "d.Listado de Turnos" <<endl;
    cout << "e.Menu Principal" <<endl;
	cout << "Seleccione opción: ";
	cin >> submenu_tur;
    cout << endl << endl;
	
	switch (submenu_tur)
	{
	case 'a':
        if (dlt >= DF)
        {
            cout <<"Sin espacio en el arreglo" <<endl;
            System();
        }
        else{
		    Alta_turno();
        }
		break;
	case 'b':
        Modif_turno();
		break;
	case 'c':
        Baja_turno();
		break;
	case 'd':
        Submenu_listados_turnos();
        break;
     case 'e':
        system("clear");
        break;
	default:
        cout << "Seleccione una opcion valida" << endl;
        System();
		break;
	}

    } while (submenu_tur != 'e');
}

void Submenu_listados_pacientes(void){

    system("clear");
    cout << "-------------------------- Pacientes ----------------------------" <<endl; 
    int listado_opcion;
    cout <<"1.Listado de pacientes" <<endl;
    cout <<"2.Busqueda de paciente" <<endl;
    cout <<"Seleccione opcion:";
    cin >> listado_opcion;

    if (listado_opcion == 1)
    {
        Listado_paciente();
    }
    else if (listado_opcion == 2)
    {
        Busqueda_paciente();
    } else{

        cout << "Seleccione una opcion valida" <<endl;
        System();
    }
}

void Submenu_listados_Especialidaes_medicas(void){

    system("clear");
    Bienvenida();
    cout << "-------------------- Especialidades Médicas ---------------------" <<endl << endl;
    int listado_opcion;
    cout <<"1.Listado de Especialidades Medicas" <<endl;
    cout <<"2.Busqueda de Especialidades Medicas" <<endl;
    cout <<"Seleccione opcion:";
    cin >> listado_opcion;

    if (listado_opcion == 1)
    {
       Listado_Especialidades_medicas();
    }
    else if (listado_opcion == 2)
    {
        Busqueda_Especialidades_medicas();
    }else{
        cout << "Seleccione una opcion valida" <<endl;
        System();
    }
}

void Submenu_listados_turnos(void){

    system("clear");
    Bienvenida();
    cout << "--------------------------- Turnos ------------------------------" <<endl <<endl;;
    int listado_opcion;
    cout <<"1.Listado de Turnos" <<endl;
    cout <<"2.Busqueda de Turnos" <<endl;
    cout <<"Seleccione opcion:";
    cin >> listado_opcion;

    if (listado_opcion == 1)
    {
        Listado_turno();
    }
    else if (listado_opcion == 2)
    {
         Busqueda_turno();

    }else{
        cout << "Seleccione una opcion valida" <<endl;
        System();
    }
}

