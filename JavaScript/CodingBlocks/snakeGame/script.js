

function init()
{
    canvas = document.getElementById("myCan");
    W = canvas.width = 600;
    H = canvas.height = 600;
    pen = canvas.getContext('2d');
    cs = 50;
    //initial score
    score = 5; 

    //mouse ==>Food
    mouse = new Image();

    //snake heads
    mouse.src ="utils/mouse.png";
    snakeU = new Image();
    snakeU.src = "utils/snakeU.png";
    snakeD = new Image();
    snakeD.src = "utils/snakeD.png";
    snakeL = new Image();
    snakeL.src = "utils/snakeL.png";
    snakeR = new Image();
    snakeR.src = "utils/snakeR.png";

    //score tropy
    tropy = new Image();
    tropy.src = "utils/tropy.png";

    food = getFood();
    gameOver = false;
    snake = {
        init_len: 5,
        color:"blue",
        cells:[],
        direction: "right",
        
        createSnake: function (){
            for(let i=this.init_len; i>0; i--)
            {
                this.cells.push({x:i,y:0});

            }
        },

        drawSnake: function() {
            pen.fillStyle = this.color;
            //for head
            var img;
            if(this.direction == "right")
                img = snakeR;
            else if(this.direction == "left")
                img = snakeL;
            else if(this.direction == "up")
                img = snakeU;
            else if(this.direction == "down")
                img = snakeD;
            pen.drawImage(img, this.cells[0].x*cs, this.cells[0].y*cs, cs-2, cs-2 );
            
            for(let i=1; i<this.cells.length; i++)
                pen.fillRect(this.cells[i].x*cs, this.cells[i].y*cs, cs-2, cs-2 );
        },

        validateCell: function(cell)
        {
            // console.log("cell.x: ", cell.x, "cell.y: ", cell.y);
            for(let i=0; i<this.cells.length; i++ )
            {
                // console.log(Scell);
                if(cell.x == this.cells[i].x && cell.y == this.cells[i].y)
                {
                    console.log("Food is inside Snake");
                    return false;
                }
            }
            // console.log("Food is in safe zone");
            return true;
        },

        updateSnake: function()
        {
            var headX = this.cells[0].x;
            var headY = this.cells[0].y;

            if(headX == food.x && headY == food.y)
            {
                var f;
                do{
                    f = getFood();
                }while(!this.validateCell(f));

                food = f;
                score++;
            }
            else
            {
                this.cells.pop();
            }

            var nextX,nextY;
            if(this.direction == "right")
            {
                nextX = headX + 1;
                nextY = headY;
            }  
            else if(this.direction == "left")
            {
                    nextX = headX - 1;
                    nextY = headY;
            }
            else if(this.direction == "up")
             {
                    nextY = headY - 1;
                    nextX = headX;
             }
            else if(this.direction == "down")
            {
                nextY=headY + 1;
                nextX = headX;
            }

            var lastX = Math.round(W/cs);
            var lastY = Math.round(H/cs);

            if(nextX > lastX || nextX <0 || nextY > lastY || nextY < 0 )
            {
                console.log("game over by edge");
                gameOver = true;
                // clearInterval(f);
                // alert("Game Over:\n You Scored: " + score);
            }
            if(!this.validateCell({x:nextX,y:nextY}))
            {
                console.log("game over by touch");
                gameOver = true;
                // clearInterval(f);
                // alert("Game Over:\n You Scored: " + score);
            }
            //   if(nextX*cs >= W)
            //   {
            //       nextX = 0;
            //   }
            //   else if(nextX <= 0)
            //     nextX = W/cs;

            // if(nextY*cs >= H)
            //   nextY = 0;
            // else if(nextY <= 0)
            //   nextY = H/cs;

            this.cells.unshift({x:nextX, y:nextY});
        },

    }

    function keyPressed(e)
    {
        if(e.key == "ArrowRight" && snake.direction != "left")
            snake.direction = "right";
        else if(e.key == "ArrowLeft" && snake.direction != "right")
            snake.direction = "left";
        else if(e.key == "ArrowUp" && snake.direction != "down")
            snake.direction = "up";
        else if(e.key == "ArrowDown" && snake.direction != "up")
            snake.direction = "down";

        // console.log('direction: ', this.direction);
    }
    
    document.addEventListener('keydown', keyPressed);

    snake.createSnake();
    
}

function draw()
{
    pen.clearRect(0,0,W,H);
    snake.drawSnake();
    pen.fillStyle = food.color;
    pen.drawImage(mouse,food.x*cs, food.y*cs, cs,cs);
    
    pen.drawImage(tropy, 32, 25, cs+10, cs+10);
    pen.font = "20px Roboto";
    pen.fillText(score, 50, 50);
}

function update()
{
    
    snake.updateSnake();
    
    // console.log("update called");
    // rect.x += rect.speed;
    // if(rect.x > W-rect.w|| rect.x < 0 )
    //     rect.speed *= -1;
}

function getFood()
{
    var foodX = Math.round(Math.random()*(W-cs)/cs);
    var foodY = Math.round(Math.random()*(H-cs)/cs);

    var food = {
        x: foodX,
        y: foodY,
        color: "red"
    }

    return food;
}


function gameLoop()
{
    if(gameOver == true)
    {
        clearInterval(f);
        alert("Game Over:\n You Scored: " + score);
    }
    draw();
    update();
}

init();
var f = setInterval(gameLoop,250);