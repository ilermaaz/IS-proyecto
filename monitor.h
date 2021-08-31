#ifndef __MONITOR__
#define __MONITOR__

#include "persona.h"
#include "sendero.h"
#include "ruta.h"
#include "parque.h"
#include "administrativo.h"

using namespace std;

class Monitor : public Persona
{
	private:

		string correoMonitor_;
		string passwordMonitor_;
		list <Parque> parques_;
		list <Ruta> rutas_;
		list <Sendero> senderos_;
		list <Monitor> empleados_;

	public:

		Monitor():Persona()
		{
			correoMonitor_ = "";
			passwordMonitor_ = "";
			parques_.clear();
			rutas_.clear();
			senderos_.clear();
			empleados_.clear();
		}

		Monitor(string nombre, string apellidos, string dni, string fecha, string direccion,
			int telefono, string correoMonitor, string passwordMonitor):Persona(nombre, apellidos, dni, fecha, direccion, telefono)
		{
			correoMonitor_ = correoMonitor;
			passwordMonitor_ = passwordMonitor;
			parques_.clear();
			rutas_.clear();
			senderos_.clear();
			empleados_.clear();
		}

		//MODIFICADORES
		void setCorreoMonitor(string correo)
		{
			correoMonitor_ = correo;
		}
		void setPasswordMonitor(string password)
		{
			passwordMonitor_ = password;
		}
		bool addRutas(Ruta r)
		{			
			list <Ruta> :: iterator it;
			for(it=rutas_.begin(); it!=rutas_.end(); it++)
			{
				if(r.getRutaId()==(*it).getRutaId())
				{
					cout << "ERROR: Esta ruta ya ha sido asignada.\n";
					return false;
				}
			}
			rutas_.push_back(r);
			cout << "Ruta asignada con exito.\n";
			return true;
		}
		bool deleteRutas(Ruta r)
		{
			list <Ruta> :: iterator it;
			for(it=rutas_.begin(); it!=rutas_.end(); it++)
			{
				if(r.getRutaId()==(*it).getRutaId())
				{
					rutas_.erase(it);
					cout << "Ruta borrada.\n";
					return true;
				}
			}
			cout << "Ruta no encontrada.\n";
			return false;
		}

		//Esta funcion añade un monitor a la lista de monitores
		bool addEmpleados(Monitor m)
		{
			list <Monitor> ::iterator it;
			for(it=empleados_.begin(); it!=empleados_.end(); it++)
			{
				if(m.getDni() == (*it).getDni())
				{
					cout << "ERROR: Este DNI ya esta registrado como un empleado Monitor\n";
					return false;
				}
			}
			empleados_.push_back(m);
			cout << "Monitor añadido con exito.\n";
			return true;
		}

		//OBSERVADORES
		string getCorreoMonitor()
		{
			return correoMonitor_;
		}
		string getPasswordMonitor()
		{
			return passwordMonitor_;
		}
};

#endif