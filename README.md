_# Proyecto final - ticketmaster2
---
##### Colaboradores:
- Braulio Chamerry 
- David Emmanuel Santana 
- Renata Flores
---
### Información General
- El presente proyecto recrea a pequeña escala un sistema de venta de boletos similar al funcionamiento de la empresa Ticketmaster. 
---
### Manual de Usuario
- Al inicio, el programa muestra un menu con 2 opciones disponibles: Cliente y Administrador.
- Este es el menu principal del programa, en el cual puedes elegir una de las opciones al presionar 1 o 2, o bien salir del programa presionando la tecla -. <br>
  _Al terminar cualquier operacion siempre puedes presionar la tecla - para regresar al menu principal._
- Al escoger una de las opciones: <br>
    - __Cliente:__ <br>
    A continuacion, se desplegara un nuevo menu con 3 opciones: Iniciar Sesion, Crear Usuario y Salir. <br>
    __NOTA:__ Si eres nuevo ingresa a la opcion "Crear Usuario" para poder asignarte tu ID. 
      - __Iniciar Sesion:__  <br>
      Se te pedira un ID ya antes proporcionado al crear un usuario. <br>
      **Entrada**: *int y contraseña* (Tu ID y contraseña). <br>
      **Salida**: *"Sesion Iniciada" + Bono por iniciar sesion*  <br>
      __NOTA:__ _En caso de no tener un ID o escribir uno incorrecto se desplegara en pantalla un mensaje de error y se volvera a mostrar
      el menu de clientes donde podras crear un usuario (en caso de que no cuentes con tu ID), o volver a escribir tu ID correctamente._ <br>
      _Tienes solamente 3 intentos para escribir tu contraseña correctamente o se mostrara un mensaje en pantalla._ <br>
      Seguido de esto se desplegara un nuevo menu con 4 opciones: Inventario, Comprar, Chambear y Salir. <br>
        - __Inventario:__ <br>
        **Entrada**: *int* (ID del boleto a usar o 0) <br>
        **Salida**: *Lista de boletos comprados* <br>
        _En caso de no contar con algun boleto, se te avisara y tendras que presionar ENTER para regresar._
        - __Comprar:__ <br> 
        **Entrada**: *int* (ID de boleto a comprar o 0 para cancelar) <br>
        Si quieres que tu boleto sea VIP presiona 1, si no presiona 0. <br>
        **Salida**: *Lista de Eventos* <br>
        __NOTA:__ En caso de no contar con el dinero suficiente, se te mencionara cual es la cantidad de dinero faltante
        y de desplegara el menu de tienda oficial. <br>
        - __Chambear:__ <br>
        **Entrada**: *N/A* <br>
        **Salida**: *Has obtenido "dinero"* <br>
        - __Salir:__ <br>
        Regresa al Menu Cliente. <br>
        **Entrada**: *N/A* <br>
        **Salida**: *Menu del Cliente* <br>
      - __Crear Usuario:__ <br>
      Ecribe una contraseña para que puedas iniciar sesion como usuario. <br>
      **Entrada**: *Contraseña (8 a 30 caracteres)* <br>
      **Salida**: *Tu contraseña, ID y un bono de dinero.* <br>
      __NOTA:__ Nuevamente se mostrara el menu de cliente donde ya podras iniciar sesion con tu ID y contraseña._ <br>
      - __Salir:__ <br>
      Regresa al Menu Principal. <br>
      **Entrada**: *N/A* <br>
      **Salida**: *Menu Principal* <br>
    - __Administrador:__ <br>
    - __Salir:__ <br>
    Sale del programa. <br>
    **Entrada**: *N/A* <br>
    **Salida**: *Guardando datos y limpiando la memoria...* <br>
    
      
      
        
  
