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
