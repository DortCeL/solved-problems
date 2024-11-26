const canvas = document.getElementById("canvas");
const context = canvas.getContext("2d");
canvas.width = "800";

const circle = {
  x: Math.floor(canvas.width / 2),
  y: Math.floor(canvas.height / 2),
  size: 30,
  dx: 12,
  dy: 7,
};

function drawCircle() {
  context.beginPath();
  context.arc(circle.x, circle.y, circle.size, 0, Math.PI * 2);
  context.fillStyle = "purple";
  context.fill();
}

function update() {
  context.clearRect(0, 0, canvas.width, canvas.height);
  drawCircle();

  //move
  circle.x += circle.dx;
  circle.y += circle.dy;

  // collision
  if (circle.x + circle.size > canvas.width || circle.x - circle.size < 0)
    circle.dx *= -1;
  if ((circle.y + circle.size > canvas.height) | (circle.y - circle.size < 0))
    circle.dy *= -1;

  requestAnimationFrame(update);
}

update();
