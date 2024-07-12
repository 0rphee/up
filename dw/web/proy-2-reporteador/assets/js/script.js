const diccionario = {
  estado: {
    title: "Estado",
    table: "estado",
    nameInTable: "Nombre",
    filtro: true,
  },
  sexo: { title: "Sexo", table: "", nameInTable: "", filtro: false },
  edad: { title: "Edad", table: "", nameInTable: "", filtro: false },
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
  primera_leng: {
    title: "1ra Lengua",
    table: "lenguaje",
    nameInTable: "Nombre",
    filtro: true,
  },
  segunda_leng: {
    title: "2da Lengua",
    table: "lenguaje",
    nameInTable: "Nombre",
    filtro: false,
  },
  frecuencia_visita: {
    title: "Frecuencia",
    table: "frec_visita",
    nameInTable: "Rango",
    filtro: true,
  },
  medio_com: {
    title: "Medio de Comunicacion",
    table: "comunicacion",
    nameInTable: "Medio",
    filtro: true,
  },
  motivo: {
    title: "Motivo de Visita",
    table: "motivos",
    nameInTable: "Motivo",
    filtro: true,
  },
  medio_transporte: {
    title: "Medio de Transporte",
    table: "transporte",
    nameInTable: "Nombre",
    filtro: true,
  },
  tiempo_traslado: {
    title: "Tiempo de Traslado",
    table: "",
    nameInTable: "",
    filtro: false,
  },
  tipo_grupo: {
    title: "Tipo de Acompañantes",
    table: "relacion",
    nameInTable: "Nombre",
    filtro: true,
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

  $.ajax({
    url: "assets/php/select.php",
    type: "POST",
    // dataType: "json",
    data: { filtros: filtros },
    success: (resp) => {
      // console.log("response", resp);
      resp = JSON.parse(resp);

      // copiar datos de 2da lengua
      if (!diccionario.segunda_leng.dict) {
        diccionario.segunda_leng.dict = structuredClone(
          diccionario.primera_leng.dict,
        );
        console.log("dic completo", diccionario);
      }

      const visitasTot = resp.length;
      let visitasNac = 0;
      let visitasExt = 0;

      let primeraLengCount = {
        data: {},
        add: function (item) {
          if (this.data[item]) {
            this.data[item]++;
          } else {
            this.data[item] = 1;
          }
        },
        getMax: function () {
          let maxKey = null;
          let maxValue = 0;
          for (let key in this.data) {
            if (this.data[key] > maxValue) {
              maxValue = this.data[key];
              maxKey = key;
            }
          }
          return [maxKey, maxValue];
        },
      };

      let segundaLengCount = {
        data: {},
        add: function (item) {
          if (this.data[item]) {
            this.data[item]++;
          } else {
            this.data[item] = 1;
          }
        },
        getMax: function () {
          let maxKey = null;
          let maxValue = 0;
          for (let key in this.data) {
            if (this.data[key] > maxValue) {
              maxValue = this.data[key];
              maxKey = key;
            }
          }
          return [maxKey, maxValue];
        },
      };
      let filas = "";

      if (resp.length === 0) {
        // if there are no results matching the filters, just empty the table
        $("#tbody").empty();
        return;
      } else {
        resp.forEach((element) => {
          filas += "<tr>";
          Object.entries(element).forEach(([_k, val]) => {
            if (diccionario[_k].dict) {
              filas += `<td>${diccionario[_k].dict[val]}</td>`;
            } else {
              filas += `<td>${val}</td>`;
            }
          });
          filas += "</tr>";

          if (element.nacionalidad == 15) {
            // 15: Mexico
            visitasNac += 1;
          } else {
            visitasExt += 1;
          }

          primeraLengCount.add(element.primera_leng);
          segundaLengCount.add(element.segunda_leng);
        });

        console.log("primera", primeraLengCount);
        console.log("segunda", segundaLengCount);

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

      let prim = diccionario.primera_leng.dict[primeraLengCount.getMax()[0]];
      let segund = diccionario.segunda_leng.dict[segundaLengCount.getMax()[0]];
      console.log(primeraLengCount.getMax(), segundaLengCount.getMax());
      $("#primera-leng").html(prim);
      $("#segunda-leng").html(segund);
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
    const select = $(`<div class="border pt-1 px-1 rounded selector">
                                    <label class="form-label mx-2" for="${key}">${itemActual.title}</label>
                                    <select class="form-select border-0" id="${key}" name="${key}">
                                        <option value="">Todos</option>
                                    </select>
                                  </div>`);
    container.prepend(select);

    if (itemActual.table) {
      $.ajax({
        url: "assets/php/filters.php",
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
