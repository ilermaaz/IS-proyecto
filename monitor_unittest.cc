#include "monitor.h"
#include <list>
#include "gtest/gtest.h"

TEST(Monitor, addRutas){
	Monitor m;
	Ruta r1("Corralito", "Fauna diversa",6,0,11,"abierto",120,4,9,"si",10);
	Ruta r2("Corralito", "Fauna diversa",6,0,11,"abierto",120,4,9,"si",10);
	Ruta r3("La laguna","Permitidos baños en el lago",3,0,10,"mantenimiento",97,6,5,"no",8);
	Ruta r4("La laguna","Permitidos baños en el lago",3,0,10,"mantenimiento",97,6,5,"no",8);

	EXPECT_TRUE(m.addRutas(r1));
	EXPECT_FALSE(m.addRutas(r2));
	EXPECT_TRUE(m.addRutas(r3));
	EXPECT_FALSE(m.addRutas(r4));
}


TEST(Monitor, deleteRutas){
	Monitor m;
	Ruta r1("Corralito", "Fauna diversa",6,0,11,"abierto",120,4,9,"si",10);
	Ruta r2("La laguna","Permitidos baños en el lago",3,0,10,"mantenimiento",97,6,5,"no",8);
	m.addRutas(r2);


	EXPECT_FALSE(m.deleteRutas(r1));
	EXPECT_TRUE(m.deleteRutas(r2));
}