#ifndef __ADMINISTRATIVO__
#define __ADMINISTRATIVO__

#include "persona.h"
#include "parque.h"
#include <list>

using namespace std;

class Administrativo : public Persona
{
	private:
		string correo_;
		string password_;
		list <Parque> parques_;

	public:

		Administrativo():Persona()
		{
			correo_ = "";
			password_ = "";
			parques_.clear();
		}

		Administrativo(string nombre, string apellidos, string dni, string fecha, string direccion, int telefono, string correo, 
						string password):Persona(nombre, apellidos, dni, fecha, direccion, telefono)
		{
			correo_ = correo;
			password_ = password;
			parques_.clear();
		}

		//MODIFICADORES
		void setCorreo(string correo)
		{
			correo_ = correo;
		}
		void setPassword(string password)
		{
			password_ = password;
		}
		bool addParque(Parque p) 
		{
			list <Parque>::iterator it;
			for(it=parques_.begin(); it!=parques_.end(); it++)
			{
				if(p.getNombre()==(*it).getNombre())
				{
					cout << "Este parque ya esta registrado.\n";
					return false;
				}
			}
			parques_.push_back(p);
			cout << "Parque incluido con exito.\n";
			return true;
		}

		//OBSERVADORES
		string getCorreo()
		{
			return correo_;
		}
		string getPassword()
		{
			return password_;
		}
};

#endif