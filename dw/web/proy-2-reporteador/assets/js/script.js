const diccionario = {
  medio_transporte: {
    title: "Medio de Transporte",
    table: "transporte",
    nameInTable: "Nombre",
    filtro: true,
  },
  tipo_grupo: {
    title: "Tipo de Acompañantes",
    table: "relacion",
    nameInTable: "Nombre",
    filtro: true,
  },
  motivo: {
    title: "Motivo de Visita",
    table: "motivos",
    nameInTable: "Motivo",
    filtro: true,
  },
  residencia: {
    title: "Pais de residencia",
    table: "pais",
    nameInTable: "Nombre",
    filtro: true,
  },
  nacionalidad: {
    title: "Nacionalidad",
    table: "pais",
    nameInTable: "Nombre",
    filtro: true,
  },
  primera_leng: {
    title: "1ra Lengua",
    table: "lenguaje",
    nameInTable: "Nombre",
    filtro: true,
  },
  frecuencia_visita: {
    title: "Frecuencia",
    table: "frec_visita",
    nameInTable: "Rango",
    filtro: true,
  },
  estado: {
    title: "Estado",
    table: "estado",
    nameInTable: "Nombre",
    filtro: true,
  },
  medio_com: {
    title: "Medio de Comunicacion",
    table: "comunicacion",
    nameInTable: "Medio",
    filtro: true,
  },
  escolaridad: {
    title: "Grado de máximo de estudios",
    table: "escolaridad",
    nameInTable: "Grado",
    filtro: true,
  },
  estado_escolar: {
    title: "Estado escolar",
    table: "visitas",
    nameInTable: "estado_escolar",
    filtro: true,
    distinct: true,
  },
  // SOLO COLUMNAS, NO FILTROS
  sexo: { title: "Sexo", table: "", nameInTable: "", filtro: false },
  edad: { title: "Edad", table: "", nameInTable: "", filtro: false },
  segunda_leng: {
    title: "2da Lengua",
    table: "lenguaje",
    nameInTable: "Nombre",
    filtro: false,
  },
  tiempo_traslado: {
    title: "Tiempo de Traslado",
    table: "",
    nameInTable: "",
    filtro: false,
  },
  tamaño_grupo: {
    title: "Tamaño del Grupo",
    table: "",
    nameInTable: "",
    filtro: false,
  },
  menores_grupo: {
    title: "Menores de 12 en el grupo",
    table: "",
    nameInTable: "",
    filtro: false,
  },
  duracion: {
    title: "Duración de visita [min]",
    table: "",
    nameInTable: "",
    filtro: false,
  },
};

function fetchData() {
  const res = $("select.form-select");

  const filtros = structuredClone(diccionario);
  res.each(function (key) {
    const currentFilterValue = $(this).val();
    const currentFilterName = $(this).attr("name");
    // if (currentFilterValue.length > 0) {
    filtros[currentFilterName].val = currentFilterValue;
    // }
  });
  // console.log("filtros", filtros);

  $.ajax({
    url: "select.php",
    type: "POST",
    // dataType: "json",
    data: { filtros: filtros ? filtros : "" },
    success: (resp) => {
      console.log("response", resp);
      resp = JSON.parse(resp);

      // copiar datos de 2da lengua
      if (!diccionario.segunda_leng.dict) {
        diccionario.segunda_leng.dict = structuredClone(
          diccionario.primera_leng.dict,
        );
      }

      const visitasTot = resp.length;
      const visitasNac = 0;
      const visitasExt = 0;

      let filas = "";

      if (resp.length === 0) {
        // if there are no results matching the filters, just empty the table
        $("#tbody").empty();
        return;
      } else {
        resp.forEach((element) => {
          filas += "<tr>";
          Object.entries(element).forEach(([_k, val]) => {
            // console.log(_k, val);
            if (_k == "segunda_leng") {
              // console.log("segunda", _k, val);
              // console.log(diccionario[_k].dict);
              // console.log(diccionario);
            }
            if (diccionario[_k].dict) {
              filas += `<td>${diccionario[_k].dict[val]}</td>`;
            } else {
              filas += `<td>${val}</td>`;
            }
          });
          filas += "</tr>";
        });

        let headers = "";
        Object.entries(resp[0]).forEach(([k, _val]) => {
          headers += `<th>${diccionario[k].title}</th>`;
        });
        $("#thead").html(headers);
        $(".table-responsive").addClass("border rounded");
      }

      $("#tbody").html(filas);
      $("#visitas-tot").html(visitasTot);

      $("#visitas-nac").html(visitasNac);

      $("#visitas-ext").html(visitasExt);
    },
    error: (err) => {
      console.error("error fetchData", err);
    },
  });
}

function fetchFilters() {
  const container = $(".accordion-body");

  Object.keys(diccionario).forEach((key) => {
    const itemActual = diccionario[key];

    if (!itemActual.filtro) {
      return;
    }
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
        success: function (resp) {
          const respJSON = JSON.parse(resp);
          // console.log(options);

          respJSON.forEach((option) => {
            /// Add dictionary of what each value of an option means
            if (!diccionario[key].dict) {
              diccionario[key].dict = {};
            }
            ////
            if (key == "estado_escolar") {
              diccionario[key].dict[option.estado_escolar] =
                option.estado_escolar;
              // console.log("aa", option);
            } else {
              diccionario[key].dict[option.id] =
                option[diccionario[key].nameInTable];
            }
            let val = "";
            if (itemActual.distinct) {
              val = new Option(
                option[itemActual.nameInTable],
                option[itemActual.nameInTable],
              );
            } else {
              val = new Option(option[itemActual.nameInTable], option.id);
            }
            $(`#${key}`).append(val);
          });
        },
      });
    }
  });
}

$(document).ready(() => {
  fetchFilters();

  // copiar datos de 2da lengua
  diccionario.segunda_leng.dict = structuredClone(
    diccionario.primera_leng.dict,
  );
  console.log("diccionario", diccionario);

  $("#btn-search").click(fetchData);
});
