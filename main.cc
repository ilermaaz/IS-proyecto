#include "administrativo.h"
#include "monitor.h"
#include "visitante.h"
#include "parque.h"
#include "sendero.h"
#include "ruta.h"

using namespace std;

int main()
{
	Sendero s1("La laguna","Permitidos baños en el lago",3,0,10,"mantenimiento");
	Sendero s2("Corralito", "Fauna diversa",6,0,11,"abierto");
	Sendero s3("Everest", "Montañoso",9,0,12,"abierto");

	Parque p1("Doñana","Huelva","Huelva","Huelva",157,"02-01-1937");
	Parque p2("Los Alcornocales","Tarifa", "Cadiz", "Cadiz", 96, "20-04-1965");
	Parque p3("Cazorla", "Jaen","Jaen","Jaen",110,"16-12-1945");

	Monitor m;
	Administrativo a;
	Ruta r;
	int opcion=1;
	string dni,password;

	cout << " ---- Registrar monitor ---- \n";
	cout << "IMPORTARTE: recordar DNI y PASSWORD\n";

	cout << "\nNombre: ";
	string nombre;
	cin >> nombre;
	m.setNombre(nombre);

	cout << "Apellidos: ";
	string apellidos;
	cin >> apellidos;
	m.setApellidos(apellidos);

	cout << "DNI: ";
	cin >> dni;
	m.setDni(dni);

	cout << "Fecha nacimiento: ";
	string fecha;
	cin >> fecha;
	m.setFecha(fecha);

	cout << "Direccion: ";
	string direccion;
	cin >> direccion;
	m.setDireccion(direccion);

	cout << "Telefono: ";
	int telefono;
	cin >> telefono;
	m.setTelefono(telefono);

	cout << "Correo: ";
	string correo;
	cin >> correo;
	m.setCorreoMonitor(correo);

	cout << "Password: ";
	cin >> password;
	m.setPasswordMonitor(password);

	m.addEmpleados(m);

	cout << " ________________________________________________________________________________________\n";
	cout << "|                                                                                        |\n";
	cout << "| --- Bienvenido al Sistema de Gestion de Parques Naturales de la Junta de Andalucia --- |\n";
	cout << "|________________________________________________________________________________________|\n";
	cout << "|                                                                                        |\n";
	cout << "|Pulsa 1 para acceder como Administrador                                                 |\n";
	cout << "|Pulsa 2 para acceder como Monitor                                                       |\n";
	cout << "|Pulsa 0 para salir de la aplicación                                                     |\n";
	cout << "|________________________________________________________________________________________|\n";
	
	do
	{
		cout << "\nAcceder como: ";
		cin >> opcion;
		switch(opcion)
		{
			case 0:
				cout << "Cerrando aplicación\n";
				break;
			case 1:
				cout << "Desabilitado por el momento\n";
				break;
			case 2:
				cout << "Introduzca DNI: \n";
				cin >> dni;
				cout << "Introduzca contraseña: \n";
				cin >> password;
				if(m.getDni() != dni or m.getPasswordMonitor() != password)
				{
					cout << "DNI o contraseña incorrectos.\n";
				}
				else
				{
					int opcion2;
					cout << " \n---- Bienvenido " << m.getNombre() << " ---- " << endl;
					do
					{
						cout << "Eliga alguna de las siguiente acciones:\n";
						cout << "1. Lista de senderos disponibles\n";
						cout << "2. Añadir una ruta\n";
						cout << "3. Eliminar una ruta\n";
						cout << "0. Cerrar sesion\n";
						cout << "Introduzca una opcion: ";
						cin >> opcion2;
						if(opcion2 == 1)
						{
							a.addParque(p1);
							a.addParque(p2);
							a.addParque(p3);
							p1.addSendero(s2);
							p1.addSendero(s3);
							p2.addSendero(s2);
							p3.addSendero(s1);
							cout <<"\n";
							p1.printSendero();
							cout <<"\n";
							p2.printSendero();
							cout <<"\n";
							p3.printSendero();
							cout <<"\n";
						}
						else if(opcion2 == 2)
						{
							cout << "Duración en minutos: ";
							float duracion;
							cin >> duracion;
							r.setDuracion(duracion);

							cout << "ID de la ruta: ";
							int id;
							cin >> id;
							r.setRutaId(id);

							cout << "Numero personas: ";
							int personas;
							cin >> personas;
							r.setCantidadPers(personas);	

							cout << "Bicicleta: ";
							string bici;
							cin >> bici;
							r.setBici(bici);

							cout << "Longitud en Km: ";
							int longitud;
							cin >> personas;
							r.setLongitud(longitud);

							m.addRutas(r);	
							cout <<"\n";
						}
						else if (opcion2 == 3)
						{
							cout << "ID de la ruta: ";
							int id;
							cin >> id;
							r.setRutaId(id);
							m.deleteRutas(r);
							cout <<"\n";
						}
						else
							cout << "Hasta la proxima " << m.getNombre() <<endl;

					}while(opcion2 != 0);
				}
				break;
			default:
				cout << "Error seleccione una opcion valida.\n";
				break;
		}

	}while(opcion != 0);

	return 0;
}