# 🧩 CPP Module 00 – Fundamentos de C++ (Clases, Objetos y Streams)

> ✅ Objetivo: Introducción a la programación orientada a objetos en C++
> ✅ Nivel: Principiante / transición desde C
> ✅ Temas clave: clases, objetos, streams, encapsulamiento, métodos, memoria básica

---

## 📚 Tabla de Contenidos

1. [Namespaces y `std::`](#-1-namespaces-y-std)
2. [Clases y Objetos](#-2-clases-y-objetos)
3. [Encapsulamiento: `private` vs `public`](#-3-encapsulamiento-private-vs-public)
4. [Constructores y Destructores](#-4-constructores-y-destructores)
5. [Métodos Miembro y `this`](#-5-métodos-miembro-y-this)
6. [Entrada y Salida con Streams](#-6-entrada-y-salida-con-streams)
7. [Errores Comunes](#-7-errores-comunes)
8. [Buenas Prácticas](#-8-buenas-prácticas)


---

## 🔹 1. Namespaces y `std::`

📘 **¿Qué es?**
Un **namespace** en C++ agrupa identificadores (funciones, clases, variables) para evitar colisiones de nombres.
El espacio de nombres `std` contiene toda la biblioteca estándar de C++.

```cpp
#include <iostream>

int main() {
	std::cout << "Hello world!" << std::endl;
	return 0;
}
```

---

## 🔹 2. Clases y Objetos

📘 **¿Qué es?**
Una **clase** es una plantilla para definir el comportamiento y estado de un tipo de objeto.
Un **objeto** es una instancia de esa clase.

```cpp
#include <iostream>

class Persona {
private:
	std::string nombre;

public:
	void setNombre(std::string n) {
		nombre = n;
	}

	void saluda() {
		std::cout << "Hola, soy " << nombre << std::endl;
	}
};

int main() {
	Persona p;                 // Se crea un objeto de tipo Persona
	p.setNombre("jfercode");   // Se asigna un nombre
	p.saluda();                // Salida: Hola, soy jfercode
}
```

🧠 **Diagrama Visual:**

```
[Clase Persona]
 ├─ nombre : string
 ├─ setNombre()
 └─ saluda()

[Objeto p]
 └─ instancia de Persona
```

---

## 🔹 3. Encapsulamiento: `private` vs `public`

📘 **¿Qué es?**
El encapsulamiento protege los datos de acceso no autorizado.

```cpp
class Caja {
private:
	int secreto; // Solo accesible dentro de la clase

public:
	void guardar(int s) { secreto = s; }
	int abrir() const { return secreto; }
};
```

🎯 **Accesos posibles:**

```
+----------------------+
|        Caja          |
+----------+-----------+
| private  | secreto   |
| public   | guardar() |
|          | abrir()   |
+----------+-----------+
```

---

## 🔹 4. Constructores y Destructores

📘 **¿Qué es?**

* **Constructor**: Método especial que se ejecuta al crear el objeto.
* **Destructor**: Método que se ejecuta al destruirlo (RAII – Resource Acquisition Is Initialization).

```cpp
class Juego {
public:
	Juego() {
		std::cout << "Comenzando juego...\n";
	}

	~Juego() {
		std::cout << "Cerrando juego...\n";
	}
};

int main() {
	Juego zelda; // Constructor llamado aquí
}               // Destructor llamado al final del scope
```

🧠 **Flujo de vida del objeto:**

```
main()
 └─ crea zelda → constructor llamado
 └─ al final del scope → destructor llamado
```

---

## 🔹 5. Métodos Miembro y `this`

📘 **¿Qué es?**
`this` es un puntero al objeto actual. Se usa, por ejemplo, para distinguir parámetros de atributos.

```cpp
class Contador {
private:
	int valor;

public:
	Contador(int valor) {
		this->valor = valor; // Desambiguación
	}

	void incrementar() {
		this->valor++;
	}

	void mostrar() const {
		std::cout << "Valor: " << this->valor << std::endl;
	}
};
```

🧠 **Desambiguación Visual:**

```
Contador(int valor)
		 ↑      ↑
	 parámetro  atributo (this->valor)
```

---

## 🔹 6. Entrada y Salida con Streams

📘 **Entrada:** `std::cin`, `std::getline`
📘 **Salida:** `std::cout`

```cpp
#include <iostream>
#include <string>

int main() {
	std::string nombre;
	
	std::cout << "Introduce tu nombre: ";
	std::getline(std::cin, nombre); // Lee línea completa (espacios incluidos)

	std::cout << "Hola, " << nombre << "!" << std::endl;
	return 0;
}
```

🎯 `std::getline()` es preferido sobre `std::cin >>` cuando hay espacios.

---

## 🔹 7. Errores Comunes

❌ Usar `cin >>` y perder parte del input con espacios
❌ No inicializar atributos
❌ Usar `using namespace std;`
❌ No separar lógica en funciones o métodos
❌ Llamar variables con nombres genéricos (`x`, `y`, `a`) que no describen propósito

---

## 🔹 8. Buenas Prácticas

✅ Usar nombres descriptivos (`nombre`, `contador`, `salario`)
✅ Usar `const` en métodos que no modifican el objeto
✅ Inicializar atributos en el constructor
✅ Comentar el propósito de las clases y métodos
✅ Escribir pruebas pequeñas en `main()` para verificar el comportamiento

---

## Autor 🤝💡📬

<div align="center">
  <tr>
	<td align="center">
	  <a href="https://github.com/jfercode">
	   <img src="https://github.com/jfercode.png" width="100px" alt="Javier Fernández Correa" />
		<br />
		<sub><b>Javier Fernández Correa</b></sub>
	  </a>
</div>


## Licencia 📜✅🗝️

Este proyecto está bajo la licencia MIT. ⚖️📄🆓