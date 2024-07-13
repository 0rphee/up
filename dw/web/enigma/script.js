let selectedCircleId = "c5";

function distributeIcons(circleId) {
  const circle = $(`#${circleId}`);
  const icons = circle.find("i");
  const iconCount = icons.length;
  const angleStep = 360 / iconCount;

  icons.each((index, icon) => {
    const angle = index * angleStep;
    const radius = "45%";
    const left = 50 + Math.cos((angle * Math.PI) / 180) * parseFloat(radius);
    const top = 50 + Math.sin((angle * Math.PI) / 180) * parseFloat(radius);

    $(icon).css({
      left: `${left}%`,
      top: `${top}%`,
    });
  });
}

function rotateCircle(circleId, direction) {
  var circle = $("#" + circleId);
  var currentRotation = parseFloat(circle.data("rotation")) || 0;

  rotAmount = { c5: 28, c4: 23, c3: 18, c2: 13, c1: 8 };
  var newRotation = currentRotation + direction * rotAmount[circleId];

  circle.data("rotation", newRotation);
  circle.css({
    transform: "rotate(" + newRotation + "deg)",
  });

  $(".circle").removeClass("selected");
  circle.addClass("selected");
}

function isColliding(element1, element2) {
  const rect1 = element1.getBoundingClientRect();
  const rect2 = element2.getBoundingClientRect();

  return !(
    rect1.right < rect2.left ||
    rect1.left > rect2.right ||
    rect1.bottom < rect2.top ||
    rect1.top > rect2.bottom
  );
}

function checkCollisions() {
  const collisionItem = document.getElementById("collision-item");
  const icons = document.querySelectorAll("i.check-pos");

  let collisionCount = 0;
  icons.forEach((icon) => {
    if (isColliding(icon, collisionItem)) {
      icon.classList.add("colliding");
      collisionCount += 1;
    } else {
      icon.classList.remove("colliding");
    }
  });
  if (collisionCount == 5) {
    alert("You win!");
  }
}

function assignRandomCheckPos(circle) {
  const icons = circle.find("i");
  const randomIndex = Math.floor(Math.random() * icons.length);
  icons.eq(randomIndex).addClass("check-pos");
}

function rotateRandomTimes(circle) {
  const randomRotations = Math.floor(Math.random() * 18) + 1; // 1 to 18 rotations
  for (let i = 0; i < randomRotations; i++) {
    const direction = Math.random() < 0.5 ? 1 : -1;
    rotateCircle(circle.attr("id"), direction);
  }
}

$(document).ready(async function () {
  const circles = $(".circle");

  circles.each(function () {
    const circle = $(this);
    const circleId = circle.attr("id");

    distributeIcons(circleId);
    assignRandomCheckPos(circle);
    rotateRandomTimes(circle);

    circle.click(function () {
      $(".circle").removeClass("selected");
      circle.addClass("selected");
      selectedCircleId = circleId;
    });
  });

  $(".rotate-button").click(async function () {
    var direction = $(this).find("i").hasClass("fa-arrow-up") ? 1 : -1;
    rotateCircle(selectedCircleId, direction);

    await new Promise((r) => setTimeout(r, 300));
    checkCollisions();
  });

  // Initial collision check after random rotations
  await new Promise((r) => setTimeout(r, 300));
  checkCollisions();
});
