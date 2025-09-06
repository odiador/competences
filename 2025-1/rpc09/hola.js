fetch("https://sistema.extraboletas.com/controlador/fachada.php", {
  "headers": {
    "accept": "application/json, text/javascript, */*; q=0.01",
    "accept-language": "es-ES,es;q=0.5",
    "content-type": "application/x-www-form-urlencoded; charset=UTF-8",
    "priority": "u=1, i",
    "sec-ch-ua": "\"Not;A=Brand\";v=\"99\", \"Brave\";v=\"139\", \"Chromium\";v=\"139\"",
    "sec-ch-ua-mobile": "?0",
    "sec-ch-ua-platform": "\"Windows\"",
    "sec-fetch-dest": "empty",
    "sec-fetch-mode": "cors",
    "sec-fetch-site": "same-origin",
    "sec-gpc": "1",
    "x-requested-with": "XMLHttpRequest"
  },
  "referrer": "https://sistema.extraboletas.com/?ev=j2jve5oxqqshi881l7yz9eagxp0kn6&pven=1",
  "body": "clase=Ventas&oper=modificarClienteDeBoletaNoImprimeDetalles&documento=1092851416&confirmacion_documento=1092851416&nombres=Juan+Manuel&apellidos=Amador+Roa&correo_electronico=arroa03%40gmail.com&indicativo_telefonico=57&telefono_celular=3136253916&tipo_documento=1&informacion_adicional_cliente=%7B%7D&boleta_cliente%5Bid_boleta%5D=3245095&boleta_cliente%5Bcliente%5D=&boleta_cliente%5Bnombre_desc%5D=GRATIS+1&boleta_cliente%5Bid_desc%5D=5976&is_auto_generated_client_info=false",
  "method": "POST",
  "mode": "cors",
  "credentials": "include"
}).then(e=> {
    e.json().then(e=>console.log(e))
}).catch(e=>console.error(e));