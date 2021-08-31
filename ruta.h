#ifndef __RUTA__
#define __RUTA__

#include "sendero.h"
#include <list>

using namespace std;

class Ruta : public Sendero
{
	private:
		float duracion_;
		int rutaId_;
		int cantidadPers_;
		string bici_;
		int longitud_;

	public:

		Ruta():Sendero()
		{
			duracion_ = 0.0;
			rutaId_ = 0;
			cantidadPers_ = 0;
			bici_ = "";
			longitud_ = 0;
		}

		Ruta(string nombre, string descripcion, int dificultad, int estado, int senderoId, string disponibilidad, float duracion, int rutaId, 
			int cantidadPers, string bici, int longitud):Sendero(nombre, descripcion, dificultad, estado, senderoId, disponibilidad)
		{
			duracion_ = duracion;
			rutaId_ = rutaId;
			cantidadPers_ = cantidadPers;
			bici_ = bici;
			longitud_ = longitud;
		}

		//MODIFICADORES
		void setDuracion(float duracion)
		{
			duracion_ = duracion;
		}
		bool setRutaId(int id)
		{
			if(id < 0)
			{
				cout << "Introduzca numeros naturales\n";
				return false;
			}
			else
			{
				rutaId_ = id;
				return true;
			}
		}
		bool setCantidadPers(int cantidadPers)
		{
			for(int i=0; i<3; i++)
			{
				if(cantidadPers <= 10 && cantidadPers >= 2)
				{
					cantidadPers_ = cantidadPers;
					cout << "Asignado correctamente.\n";
					return true;
				}
				else
				{
					cout << "Por favor, eliga entre un minimo de 2 y un maximo de 10.\n" << endl;
					cout << "Numero de personas:\n";
					cin >> cantidadPers;
				}
			}
			cout << "Número de personas no asignado.\n";
			return false;
		}
		bool setBici(string bici)
		{
			if(bici == "si" or bici == "Si")
			{
				bici_ = bici;
				return true;
			}
			else
			{
				bici_ = bici;
				return false;
			}
		}
		void setLongitud(int longitud)
		{
			longitud_ = longitud;
		}
		//OBSERVADORES
		float getDuracion()
		{
			return duracion_;
		}
		int getRutaId()
		{
			return rutaId_;
		}
		int getCantidadPers()
		{
			return cantidadPers_;
		}
		string getBici()
		{
			return bici_;
		}
		int getLongitud()
		{
			return longitud_;
		}
};

#endif
