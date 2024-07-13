let selectedCircleId = "c1";

function distributeIcons(circleId) {
  const circle = $(`#${circleId}`);
  const icons = circle.find("i");
  const iconCount = icons.length;
  const angleStep = 360 / iconCount;

  icons.each((index, icon) => {
    const angle = index * angleStep;
    const radius = "45%"; // Adjust this value to change the distance from the center
    const left = 50 + Math.cos((angle * Math.PI) / 180) * parseFloat(radius);
    const top = 50 + Math.sin((angle * Math.PI) / 180) * parseFloat(radius);

    $(icon).css({
      left: `${left}%`,
      top: `${top}%`,
    });
  });
}

// Function to rotate the circle itself
function rotateCircle(circleId, direction) {
  var circle = $("#" + circleId);
  var currentRotation = parseFloat(circle.data("rotation")) || 0;
  var newRotation = currentRotation + direction * 20; // Adjust rotation speed as needed

  circle.data("rotation", newRotation);
  circle.css({
    transform: "rotate(" + newRotation + "deg)",
  });

  // Toggle selected class for circles with fade-in effect
  $(".circle").removeClass("selected");
  circle.addClass("selected");
}

// Function to check if an element is within 10% of the viewport's middle line
function isNearMiddleLine(element) {
  const viewportHeight = window.innerHeight;
  const middleLine = viewportHeight / 2;
  const toleranceAbove = viewportHeight * 0.1; // 10% of viewport height above
  const toleranceBelow = viewportHeight * 0.1; // 10% of viewport height below
  const rect = element.getBoundingClientRect();

  // Calculate the middle of the element
  const elementMiddle = rect.top + rect.height / 2;

  // Calculate the bounds of the tolerance zone
  const upperBound = middleLine - toleranceAbove;
  const lowerBound = middleLine + toleranceBelow;

  console.log("vh", viewportHeight, "middle", middleLine);
  console.log(lowerBound, "<=", elementMiddle, "<=", upperBound);
  // console.log("element middle position", elementMiddle);
  // console.log("upperBound", upperBound);
  // console.log("lowerBound", lowerBound);

  // Check if the middle of the element is within the tolerance zone
  return elementMiddle >= upperBound && elementMiddle <= lowerBound;
}

// Function to check all elements with 'check-pos' class
function checkPositions() {
  const elements = document.querySelectorAll(".check-pos");

  elements.forEach((element) => {
    if (isNearMiddleLine(element)) {
      element.classList.add("near-middle");
      console.log(`Element ${element.id || "unknown"} is near the middle line`);
    } else {
      element.classList.remove("near-middle");
    }
  });
}

$(document).ready(function () {
  const circles = $(".circle");

  circles.each(function () {
    const circle = $(this);
    const circleId = circle.attr("id");

    // Distribute icons for each circle
    distributeIcons(circleId);

    // Click handler to select circle and apply border
    circle.click(function () {
      $(".circle").removeClass("selected");
      circle.addClass("selected");
      selectedCircleId = circleId;
    });
  });

  // Event handler for rotate buttons
  $(".rotate-button").click(async function () {
    var direction = $(this).find("i").hasClass("fa-arrow-up") ? 1 : -1;
    // checkPositions();
    rotateCircle(selectedCircleId, direction);

    // without this wait, it will check the positions before the movement animation plays out
    await new Promise((r) => setTimeout(r, 250));
    checkPositions();
  });
});
