const diccionarioFiltros = {
  medio_transporte: {
    title: "Medio de Transporte",
    table: "transporte",
    nameInTable: "Nombre",
  },
  tipo_grupo: {
    title: "Tipo de Acompañantes",
    table: "relacion",
    nameInTable: "Nombre",
  },
  motivo: {
    title: "Motivo de Visita",
    table: "motivos",
    nameInTable: "Motivo",
  },
  residencia: {
    title: "Pais de residencia",
    table: "pais",
    nameInTable: "Nombre",
  },
  nacionalidad: { title: "Nacionalidad", table: "pais", nameInTable: "Nombre" },
  primera_leng: {
    title: "1ra Lengua",
    table: "lenguaje",
    nameInTable: "Nombre",
  },
  frecuencia_visita: {
    title: "Frecuencia",
    table: "frec_visita",
    nameInTable: "Rango",
  },
  estado: { title: "Estado", table: "estado", nameInTable: "Nombre" },
  medio_com: {
    title: "Medio de Comunicacion",
    table: "comunicacion",
    nameInTable: "Medio",
  },
  escolaridad: {
    title: "Grado de máximo de estudios",
    table: "escolaridad",
    nameInTable: "Grado",
  },
  estado_escolar: {
    title: "Estado escolar",
    table: "visitas",
    nameInTable: "estado_escolar",
    distinct: true,
  },
};

const diccionario = {
  estado: { title: "Estado", table: "estado", nameInTable: "" },
  sexo: { title: "Sexo", table: "", nameInTable: "" },
  edad: { title: "Edad", table: "", nameInTable: "" },
  residencia: { title: "Pais de residencia", table: "pais", nameInTable: "" },
  nacionalidad: { title: "Nacionalidad", table: "pais", nameInTable: "" },
  escolaridad: { title: "Estudios", table: "escolaridad", nameInTable: "" },
  estado_escolar: { title: "Grado", table: "", nameInTable: "" },
  primera_leng: { title: "1ra Lengua", table: "lenguaje", nameInTable: "" },
  segunda_leng: { title: "2da Lengua", table: "lenguaje", nameInTable: "" },
  frecuencia_visita: {
    title: "Frecuencia",
    table: "frec_visita",
    nameInTable: "",
  },
  medio_com: {
    title: "Medio de Comunicacion",
    table: "comunicacion",
    nameInTable: "",
  },
  motivo: { title: "Motivo de Visita", table: "motivos", nameInTable: "" },
  medio_transporte: {
    title: "Medio de Transporte",
    table: "transporte",
    nameInTable: "",
  },
  tiempo_traslado: { title: "Tiempo de Traslado", table: "", nameInTable: "" },
  tipo_grupo: {
    title: "Tipo de Acompañantes",
    table: "relacion",
    nameInTable: "",
  },
  tamaño_grupo: { title: "Tamaño del Grupo", table: "", nameInTable: "" },
  menores_grupo: {
    title: "Menores de 12 en el grupo",
    table: "",
    nameInTable: "",
  },
  duracion: { title: "Duración de visita [min]", table: "", nameInTable: "" },
};

function fetchData() {
  const queryVal = $("#query").val();

  if (queryVal.trim().length == 0) {
    alert("Campo de texto vacío");
    return;
  }

  console.log("QUERY VALUE:", queryVal);
  $.ajax({
    url: "select.php",
    type: "POST",
    // dataType: "json",
    data: { query: queryVal },
    success: (resp) => {
      // console.log(resp);
      resp = JSON.parse(resp);
      // console.log(resp);

      let filas = "";

      resp.forEach((element) => {
        filas += "<tr>";
        Object.entries(element).forEach(([_k, val]) => {
          if (_k == "ID") {
            filas += `<th>${val}</th>`;
          } else {
            filas += `<td>${val}</td>`;
          }
        });
        filas += "</tr>";
      });

      let headers = "";
      Object.entries(resp[0]).forEach(([k, _val]) => {
        headers += `<th>${k}</th>`;
      });

      $("#thead").html(headers);
      $("#tbody").html(filas);
    },
    error: (err) => {
      console.error(err);
    },
  });
}

function fetchFilters() {
  const container = $(".accordion-body");

  Object.keys(diccionarioFiltros).forEach((key) => {
    const itemActual = diccionarioFiltros[key];
    const select = $(`<div class="border pt-1 px-1 rounded">
                                    <label class="form-label mx-2" for="${key}">${itemActual.title}</label>
                                    <select class="form-select border-0" id="${key}" name="${key}">
                                        <option value="">Todos</option>
                                    </select>
                                  </div>`);
    container.prepend(select);

    if (itemActual.table) {
      $.ajax({
        url: "filters.php",
        method: "POST",
        data: itemActual,
        success: function (data) {
          console.log(key,data);
          const options = JSON.parse(data);
          options.forEach((option) => {
            let val = "";
            if (itemActual.distinct) {
              val = new Option(option[itemActual.nameInTable], option[itemActual.nameInTable]);
            } else {
              val = new Option(option[itemActual.nameInTable], option.id);
            }
            console.log(val);
            $(`#${key}`).append(val);
          });
        },
      });
    }
  });
}

$(document).ready(fetchFilters);
