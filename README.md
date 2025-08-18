# Submit-1

Proyecto realizado por **Samuel F. Moncayo**, **Juan D. Valencia**, **José M. López** y **María C. Caicedo**.

---

## 📌 Descripción

Este repositorio contiene tres implementaciones en C++ para calcular valores de π:

- **carlopi.cpp**
- **carlopi_concurrent.cpp**
- **taylorpi.cpp**

También incluye un informe comparativo en PDF llamado **Comparacion Carlopi.pdf**.

---

## 📂 Archivos

| Archivo                       | Descripción                                                                 |
|-------------------------------|-----------------------------------------------------------------------------|
| `carlopi.cpp`                 | Cálculo de π con un método clásico secuencial.                              |
| `carlopi_concurrent.cpp`      | Versión concurrente/paralela del cálculo de π.                              |
| `taylorpi.cpp`                | Cálculo de π usando la serie de Taylor.                                     |
| `Comparacion Carlopi.pdf`     | Informe que compara el desempeño entre los métodos.                         |
| `.gitignore`                  | Especifica archivos que Git debe ignorar.                                   |
| `.gitattributes`              | Define atributos para el control de versiones.                              |

---

## ⚙️ Requisitos

- Compilador C++ moderno (por ejemplo, `g++` o `clang++`) con soporte para **C++11 o superior**.  
- Sistema operativo: multiplataforma (Linux, macOS, Windows).  
- Opcional: herramientas o scripts adicionales para ejecutar pruebas concurrentes.  

---

## ▶️ Ejecución

### 1. Secuencial (carlopi.cpp)

```bash
g++ carlopi.cpp -o carlopi
./carlopi
```

### 2. Concurrente (carlopi_concurrent.cpp)

```bash
g++ carlopi_concurrent.cpp -pthread -o carlopi_concurrent
./carlopi_concurrent
```

### 3. Serie de Taylor (taylorpi.cpp)

```bash
g++ taylorpi.cpp -o taylorpi
./taylorpi
```

---

## 📊 Comparación de resultados

Consulta **Comparacion Carlopi.pdf** para ver un análisis detallado del rendimiento, precisión y eficiencia entre los tres enfoques implementados.



---

## 👨‍💻 Contacto

Proyecto colaborativo de:

- Samuel F. Moncayo  
- Juan D. Valencia  
- José M. López  
- María C. Caicedo 
