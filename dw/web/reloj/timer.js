const hr = document.getElementById("hr");
const min = document.getElementById("min");
const seg = document.getElementById("seg");

var timer = [0, 0, 0];

function updateTimer() {
    let h = "0" + timer[0];
    let m = "0" + timer[1];
    let s = "0" + timer[2];

    h = h.substring(h.length - 2, h.length);
    m = m.substring(m.length - 2, m.length);
    s = s.substring(s.length - 2, s.length);

    hr.innerHTML = h;
    min.innerHTML = m;
    seg.innerHTML = s;

    // setTimeout(updateTimer, 1000);
}


function setTimer(mod, pos) {
    let max = 59;
    let overflowFunc;
    let underflowFunc;

    switch (pos) {
        case 0:
            // hours
            max = 23;
            overflowFunc = () => { };
            underflowFunc = () => { };
            break;
        case 1:
            // minutes
            overflowFunc = () => setTimer(+1, 0);;
            underflowFunc = () => setTimer(-1, 0);;
            break;
        case 2:
            // seconds
            overflowFunc = () => setTimer(+1, 1);;
            underflowFunc = () => setTimer(-1, 1);;
            break;
    }
    if (timer[pos] + mod < 0) {
        // underflow
        timer[pos] = max;
        underflowFunc();
    } else if (timer[pos] + mod > max) {
        // overflow
        timer[pos] = 0;
        overflowFunc();
    } else {
        timer[pos] += mod;
    }
    updateTimer()
}

updateTimer();
