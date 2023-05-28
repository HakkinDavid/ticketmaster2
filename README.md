# Proyecto final - Ticketmaster2
---
##### Colaboradores:
- Braulio Chamerry
- David Emmanuel Santana Romero
- Renata Flores
---
### Información general
- El presente proyecto recrea (a pequeña escala) un sistema de venta de boletos similar al funcionamiento de la empresa Ticketmaster.
---
### Manual de usuario
- Al inicio, el programa muestra un menú con 2 opciones disponibles: Cliente y Administrador.
- Este es el menú principal del programa, elige una de las opciones al presionar 1 o 2, o bien, sal del programa presionando la tecla -.<br>
- Al escoger una de las opciones:<br>
    - __Cliente:__<br>
    A continuación, se desplegará un nuevo menú con 3 opciones: Iniciar sesión, Crear usuario y Salir.<br>
    __NOTA:__ Si no cuentas con un usuario, ingresa a la opción "Crear usuario" para asignarte un ID.
      - __Iniciar sesión:__<br>
      Inicia sesión con tu cuenta Ticketmaster2<br>
      **Entrada**: *int y string* (tu ID y contraseña).<br>
      **Salida**: *"Sesión iniciada. Bono por iniciar sesión: +$(" + bono + ")"*<br>
      __NOTA:__ _En caso de ingresar un ID no válido, se muestra en pantalla un mensaje de error y se regresa al menú de clientes._<br>
      _Solo cuentas con 3 intentos para escribir la contraseña correctamente, de lo contrario se mostrará un mensaje de error en pantalla y regresarás al menú de clientes._<br>
      Posteriormente, se desplegará un nuevo menú con 4 opciones: Inventario, Comprar, Chambear y Salir.<br>
        - __Inventario:__<br>
        **Entrada**: *int* (ID del boleto a usar o 0 para cancelar)<br>
        **Salida**: *Lista de boletos comprados*<br>
        _En caso de no tener boletos, se muestra un mensaje indicando presionar ENTER para regresar._
        - __Comprar:__<br>
        **Entrada**: *int* (ID del boleto a comprar o 0 para cancelar)<br>
        Si quieres comprar la experiencia VIP presiona 1, en caso contrario presiona 0.<br>
        **Salida**: *Lista de Eventos*<br>
        __NOTA:__ Si no cuentas con el dinero suficiente para alguna transacción, se te indicará cuánto dinero hace falta.<br>
        - __Chambear:__<br>
        **Entrada**: *N/A*<br>
        **Salida**: *Has obtenido +$" + dinero + "*<br>
        - __Salir:__<br>
        Regresa al menú del cliente.<br>
        **Entrada**: *N/A*<br>
        **Salida**: *Menú del cliente*<br>
      - __Crear usuario:__<br>
      Escribe una contraseña para iniciar sesión como usuario.<br>
      **Entrada**: *Contraseña (de 8 a 30 caracteres)*<br>
      **Salida**: *Tu contraseña representada en asteriscos, ID y un bono de creación de cuenta.*<br>
      __NOTA:__  _Nuevamente se mostrará el menú del cliente, donde ya se puede iniciar sesión con tu ID asignado y contraseña._<br>
      - __Salir:__<br>
      Regresa al menú principal.<br>
      **Entrada**: *N/A*<br>
      **Salida**: *Menú principal*<br>
    - __Administrador:__<br>
    **Entrada**: *Contraseña* (Por defecto, previo a configurar el programa es "blockbuster123")<br>
    __NOTA:__ _Solo cuentas con 3 intentos para escribir la contraseña correctamente, de lo contrario se mostrará un mensaje de error en pantalla y regresarás al menú de clientes._<br>
    Posteriormente, se desplegará un menú con herramientas útiles para administrar Ticketmaster2.
    **Salida**: *Menú del administrador*<br>
      - __Crear evento:__<br>
      Crea un nuevo evento.<br>
      **Entrada**: *Detalles del evento* (nombre, lugar, año, mes, día, hora, minuto, artista, dirección, precio)<br>
      **Salida**: *N/A*<br>
      - __Estadísticas de ventas:__<br>
      Muestra las ganancias generadas por la venta de boletos.<br>
      **Entrada**: *float* (costo administrativo)<br>
      **Salida**: *Ingresos totales, ganancias, porcentaje de ganancias.*<br>
      - __Información de usuarios:__<br>
      **Entrada**: *N/A*<br>
      **Salida**: *Lista de información de clientes* (ID, cantidad de boletos, saldo actual)<br>
      - __Cambiar contraseña maestra:__<br>
      **Entrada**: *Contraseña* (de 8 a 30 caracteres)<br>
      **Salida**: *Contraseña* (oculta)<br>
      - __Salir__<br>
      Regresa al menú principal.<br>
      **Entrada**: *N/A*<br>
      **Salida**: *Menú principal*<br>
    - __Salir:__<br>
    Sale del programa.<br>
    **Entrada**: *N/A*<br>
    **Salida**: *"Guardando datos y limpiando la memoria..."*<br>