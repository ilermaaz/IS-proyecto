#ifndef __PERSONA__
#define __PERSONA__

#include <iostream>
#include <string>

using namespace std;

class Persona
{
	private:
		string nombre_;
		string apellidos_;
		string dni_;
		string fecha_;
		string direccion_;
		int telefono_;

	public:

		//CONSTRUCTOR VACIO
		Persona()
		{
			nombre_ = "";
			apellidos_ = "";
			dni_ = "";
			fecha_ = "";
			direccion_ = "";
			telefono_ = 0;
		}

		//CONSTRUCTOR PARAMETRIZADO
		Persona(string nombre, string apellidos, string dni, string fecha, string direccion, int telefono)
		{
			nombre_ = nombre;
			apellidos_ = apellidos;
			dni_ = dni;
			fecha_ = fecha;
			direccion_ = direccion;
			telefono_ = telefono;
		}

		//MODIFICADORES
		void setNombre(string nombre)
		{
			nombre_ = nombre;
		}
		void setApellidos(string apellidos)
		{
			apellidos_ = apellidos;
		}
		void setDni(string dni)
		{
			dni_ = dni;
		}
		void setFecha(string fecha)
		{
			fecha_ = fecha;
		}
		void setDireccion(string direccion)
		{
			direccion_ = direccion;
		}
		void setTelefono(int telefono)
		{
			telefono_ = telefono;
		}

		//OBSERVADORES
		string getNombre()
		{
			return nombre_;
		}
		string getApellidos()
		{
			return apellidos_;
		}
		string getDni()
		{
			return dni_;
		}
		string getFecha()
		{
			return fecha_;
		}
		string getDireccion()
		{
			return direccion_;
		}
		int getTelefono()
		{
			return telefono_;
		}

		//OPERACIONES
		void imprimirContacto()
		{
			cout << "Nombre: " << getNombre() << endl;
			cout << "Apellidos: " << getApellidos() << endl;
			cout << "DNI: " << getDni() << endl;
			cout << "Fecha nacimiento: " << getFecha() << endl;
			cout << "Direccion: " << getDireccion() << endl;
			cout << "Telefono: " << getTelefono() << endl;
		}
};

#endif