function Turtle(context) {
    function toRadians(angle) {
        return angle * Math.PI / 180;
    }
    
    function drawLine(x1, y1, x2, y2) {
        context.beginPath();
        context.moveTo(x1, y1);
        context.lineTo(x2, y2);
        context.stroke();
    }
    
    this.angle                               // current angle
        = this.currentX = this.currentY = 0; // current position
        
    var wx1 = wy1 = wx2 = wy2                // canvas coordination
        = vx1 = vy1 = vx2 = vy2              // viewable area
        = factX = factY = 0;                 // scale 
        
    this.context = context;
    
    this.window = function(x1, y1, x2, y2) {
        wx1 = x1;
        wy1 = y1;
        wx2 = x2;
        wy2 = y2;
        factX = (vx2 - vx1) / (wx2 - wx1);
        factY = (vy2 - vy1) / (wy2 - wy1);    
    };
    
    this.view = function(x1, y1, x2, y2) {
        this.context.beginPath();
        this.context.rect(x1, y1, x2 - x1, y2 - y1);
        this.context.clip();
        this.context.stroke();
        this.context.closePath();
        vx1 = x1;
        vy1 = y1;
        vx2 = x2;
        vy2 = y2;
        factX = (vx2 - vx1) / (wx2 - wx1);
        factY = (vy2 - vy1) / (wy2 - wy1);
    };
    
    this.setPoint = function(x, y) {
        this.currentX = x;
        this.currentY = y;
    };
    
    this.setAngle = function(a) {
        this.angle = a;
    };
    
    this.warp = function(l) {
        this.setPoint(this.currentX + l * Math.cos(toRadians(this.angle)),
                      this.currentY + l * Math.sin(toRadians(this.angle)));
    };
    
    this.move = function(l) {
        var x = this.currentX + l * Math.cos(toRadians(this.angle));
        var y = this.currentY + l * Math.sin(toRadians(this.angle));
        var x1 = (this.currentX - wx1) * factX + vx1;
        var y1 = (wy2 - this.currentY) * factY + vy1;
        var x2 = (x - wx1) * factX + vx1;
        var y2 = (wy2 - y) * factY + vy1;
        drawLine(x1, y1, x2, y2);
        this.setPoint(x, y);
    };
    
    this.moveTo = function(x, y) {
        var x1 = (this.currentX - wx1) * factX + vx1;
        var y1 = (wy2 - this.currentY) * factY + vy1;
        var x2 = (x - wx1) * factX + vx1;
        var y2 = (wy2 - y) * factY + vy1;
        drawLine(x1, y1, x2, y2);
        this.setPoint(x, y);  
    };
    
    this.pset = function(x, y) {
        drawLine(x, y, x + 1, y + 1);
    };
    
    this.line = function(x1, y1, x2, y2) {
        this.setPoint(x1, y1);
        this.moveTo(x2, y2);
    };
     
    this.turn = function(a) {
        this.angle = this.angle + a;
        this.angle = this.angle % 360;
    };
    
    this.polygon = function(tri) {
        this.context.beginPath();
        this.context.moveTo(tri[0].x, tri[0].y);
        for(var i = 1; i < tri.length; i++) {
            this.context.lineTo(tri[i].x, tri[i].y);
        }
        this.context.closePath();
        this.context.fill();
    };
}