#ifndef __VISITANTE__
#define __VISITANTE__

#include "persona.h"
#include <list>

using namespace std;

class Visitante : public Persona
{
	private:
		list <string> requisitos_;

	public:

		Visitante():Persona()
		{
			requisitos_.clear();
		}

		Visitante(string nombre, string apellidos, string dni, string fecha, string direccion, int telefono):Persona(nombre, 
					apellidos, dni, fecha, direccion, telefono)
		{
			requisitos_.clear();
		}

		//MODIFICADORES
		bool addRequisitos(string req)
		{
			list <string> :: iterator it;
			for(it=requisitos_.begin(); it!=requisitos_.end(); it++)
			{
				if(req==(*it))
				{
					cout << "ERROR: Este requisito ya esta registrado" << endl;
					return false;
				}
			}
			requisitos_.push_back(req);
			cout << "Requisito incluido con exito" << endl;
			return true;
		}
		bool deleteRequisitos(string req)
		{
			list <string> :: iterator it;
			for(it=requisitos_.begin(); it!=requisitos_.end(); it++)
			{
				if(req==(*it))
				{
					requisitos_.erase(it);
					cout << "Requisito borrado\n";
					return true;
				}
			}
			cout << "Requisito no encontrado\n";
			return false;
		}

		//OBSERVADORES
		list <string> getRequisitos()
		{
			return requisitos_;
		}
};

#endif