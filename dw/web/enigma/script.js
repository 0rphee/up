let selectedCircleId = "c1";
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

$(document).ready(function () {
  const circles = $(".circle");

  circles.each(function () {
    const circle = $(this);

    // Click handler to select circle and apply border
    circle.click(function () {
      $(".circle").removeClass("selected");
      circle.addClass("selected");
      selectedCircleId = $(this).attr("id");
    });
  });

  // Event handler for rotate buttons
  $(".rotate-button").click(function () {
    var direction = $(this).hasClass("fa-arrow-up") ? 1 : -1;
    rotateCircle(selectedCircleId, direction);
  });
});
