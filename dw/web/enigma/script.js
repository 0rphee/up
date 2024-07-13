let selectedCircleId = "c1";

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
  var newRotation = currentRotation + direction * 20;

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
  const collisionItem = document.getElementById("collisionItem");
  const icons = document.querySelectorAll("i.check-pos");

  icons.forEach((icon) => {
    if (isColliding(icon, collisionItem)) {
      icon.classList.add("colliding");
      console.log(`Icon is colliding with the item`);
    } else {
      icon.classList.remove("colliding");
    }
  });
}

$(document).ready(function () {
  const circles = $(".circle");

  // Create and position the collision item
  const ruedaContainer = $(".rueda-container");
  const collisionItem = $("<div id='collisionItem'></div>");
  collisionItem.css({
    position: "relative",
    left: "0%",
    top: "0%",
    height: "1px",
    width: "45%",
    backgroundColor: "red",
    transform: "translate(-50%, -50%)",
    zIndex: 1000,
  });
  ruedaContainer.append(collisionItem);

  circles.each(function () {
    const circle = $(this);
    const circleId = circle.attr("id");

    distributeIcons(circleId);

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
});
