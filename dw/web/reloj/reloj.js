function updateClock() {
    console.log("aa")
    const reloj = document.getElementById("reloj");
    let f = new Date();
    let h = "0" + f.getHours();
    let m = "0" + f.getMinutes();
    let s = "0" + f.getSeconds();

    h = h.substring(h.length - 2, h.length);
    m = m.substring(m.length - 2, m.length);
    s = s.substring(s.length - 2, s.length);

    reloj.innerHTML = h + ":" + m + ":" + s;
    setTimeout(() => { updateClock(); }, 1000);
}

updateClock();
