#ifndef __SENDERO__
#define __SENDERO__

#include <iostream>
#include <string>

using namespace std;

class Sendero
{
	private:
		string nombre_;
		string descripcion_;
		int dificultad_;
		int estado_;
		int senderoId_;
		string disponibilidad_;

	public:

		Sendero()
		{
			nombre_ = "";
			descripcion_ = "";
			dificultad_ = 0;
			estado_ = 0;
			senderoId_ = 0;
			disponibilidad_ = "";
		}

		Sendero(string nombre, string descripcion, int dificultad, int estado, int senderoId, string disponibilidad)
		{
			nombre_ = nombre;
			descripcion_ = descripcion;
			dificultad_ = dificultad;
			estado_ = estado;
			senderoId_ =senderoId;
			disponibilidad_ = disponibilidad;
		}

		//MODIFICADORES
		void setNombre(string nombre)
		{
			nombre_ = nombre;
		}
		void setDescripcion(string descripcion)
		{
			descripcion_ = descripcion;
		}
		bool setDificultad(int dificultad)
		{
			if(dificultad <= 10 && dificultad >=0)
			{
				dificultad_ = dificultad;
				return true;
			}
			else
			{
				cout << "Valores admitidos entre 0 y 10" << endl;
				return false;
			}
		}
		void setEstado(int estado)
		{
			estado_ = estado;
		}
		bool setSenderoId(int id)
		{
			if(id < 0)
			{
				cout << "Introduzca numeros naturales\n";
				return false;
			}
			else
			{
				senderoId_ = id;
				return true;
			}
		}
		bool setDisponibilidad(string disponibilidad)
		{
			if(disponibilidad == "abierto" || disponibilidad == "cerrado" || disponibilidad == "mantenimiento")
			{
				disponibilidad_ = disponibilidad;
				return true;
			}
			else
			{
				cout << "Debe elegir entre:\n";
				cout << "1.Abierto\n";
				cout << "2.Cerrado\n";
				cout << "3.Mantenimiento\n";
				return false;
			}
		}

		//OBSERVADORES
		string getNombre()
		{
			return nombre_;
		}
		string getDescripcion()
		{
			return descripcion_;
		}
		int getDificultad()
		{
			return dificultad_;
		}
		int getEstado()
		{
			return estado_;
		}
		int getSenderoId()
		{
			return senderoId_;
		}
		string getDisponibilidad()
		{
			return disponibilidad_;
		}
};

#endif