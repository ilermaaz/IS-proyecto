#ifndef __PARQUE__
#define __PARQUE__

#include "ruta.h"
#include "sendero.h"

class Parque
{
	private:
		string nombre_;
		string ubicacion_;
		string localidad_;
		string provincia_;
		int superficie_;
		string fechaDeclaracion_; 
		list <string> reconocimientos_;
		list <Sendero> senderos_;

	public:

		Parque()
		{
			nombre_ = "";
			ubicacion_ = "";
			localidad_ = "";
			provincia_ = "";
			superficie_ = 0;
			fechaDeclaracion_ = "";
			reconocimientos_.clear();
			senderos_.clear();
		}

		Parque(string nombre, string ubicacion, string localidad, string provincia, int superficie, string fechaDeclaracion)
		{
			nombre_ = nombre;
			ubicacion_ = ubicacion;
			localidad_ = localidad;
			provincia_ = provincia;
			superficie_ = superficie;
			fechaDeclaracion_ = fechaDeclaracion;
			reconocimientos_.clear();
			senderos_.clear();
		}

		//MODIFICADORES
		void setNombre(string nombre)
		{
			nombre_ = nombre;
		}
		void setUbicacion(string ubicacion)
		{
			ubicacion_ = ubicacion;
		}
		void setLocalidad(string localidad)
		{
			localidad_ = localidad;
		}
		void setProvincia(string provincia)
		{
			provincia_ = provincia;
		}
		void setSuperficie(int superficie)
		{
			superficie_ = superficie;
		}
		void setFecha(string fecha)
		{
			fechaDeclaracion_ = fecha;
		}
		bool addReconocimientos(string rec)
		{
			list <string> :: iterator it;
			for(it=reconocimientos_.begin(); it!=reconocimientos_.end(); it++)
			{
				if(rec==(*it))
				{
					cout << "ERROR: Este reconocimiento ya esta incluido" << endl;
					return false;
				}
			}
			reconocimientos_.push_back(rec);
			cout << "Reconocimiento incluido con exito" << endl;
			return true;
		}
		bool addSendero(Sendero s) 
		{
			list <Sendero>::iterator it;
			for(it=senderos_.begin(); it!=senderos_.end(); it++)
			{
				if(s.getSenderoId()==(*it).getSenderoId())
				{
					cout << "Este sendero ya esta registrado.\n";
					return false;
				}
			}
			senderos_.push_back(s);
			cout << "Sendero incluido con exito.\n";
			return true;
		}
		void printSendero()
		{
			cout << " === Parque de " << getNombre() << " tiene estos senderos === \n";
			list <Sendero>::iterator it;
			for(it=senderos_.begin(); it!=senderos_.end(); it++)
			{
				cout << "Nombre: " << it->getNombre() << endl;
				cout << "Descripcion: " << it->getDescripcion() << endl;
				cout << "Dificultad: " << it->getDificultad() << endl;
				cout << "Estado: " << it->getEstado() << endl;
				cout << "ID: " << it->getSenderoId() << endl;
				cout << "Disponibilidad: " << it->getDisponibilidad() << endl;
				cout << "\n";
			}
		}

		//OBSERVADORES
		string getNombre()
		{
			return nombre_;
		}
		string getUbicacion()
		{
			return ubicacion_;
		}
		string getLocalidad()
		{
			return localidad_;
		}
		string getProvincia()
		{
			return provincia_;
		}
		int getSuperficie()
		{
			return superficie_;
		}
		string getFecha()
		{
			return fechaDeclaracion_;
		}
		list <string> getReconocimientos()
		{
			return reconocimientos_;
		}
		list <Sendero> getSenderos()
		{
			return senderos_;
		}
		int getNumeroSenderos()
		{
			return senderos_.size();
		}
};

#endif