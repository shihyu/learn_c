function TetrixPiece(type) {
    type = type || parseInt(Math.random() * 7 + 1);
    
    var pieceType = 0;
    var coordinates = [];
    for(var i = 0; i < 4; i++) {
        coordinates[i] = [];
    }
    
    this.initialize = function(type) {
        if (type < 1 || type > 7) {
            type = 1;
        }
        // set coord. for each block
        pieceType = type;
        for(var i = 0 ;i < 4 ;i++) {
            coordinates[i][0] = TetrixPiece.pieceTypes[pieceType - 1][i][0];
            coordinates[i][1] = TetrixPiece.pieceTypes[pieceType - 1][i][1];
        }
    };
    
    this.initialize(type);

    this.rotateLeft = function() {
        // do not rotate square piece
        if(pieceType == 5) {
            return;
        }
        var tmp;
        for(var i = 0; i < 4; i++) {
            tmp = this.getBlockXCoord(i);  
            this.setBlockXCoord(i, this.getBlockYCoord(i));
            this.setBlockYCoord(i, -tmp);
        }
    };

    this.rotateRight = function() {
        // do not rotate square piece
        if(pieceType == 5) {
            return;
        }
        var tmp;
        for(var i = 0; i < 4; i++) {
            tmp = this.getBlockXCoord(i);
            this.setBlockXCoord(i, -this.getBlockYCoord(i));
            this.setBlockYCoord(i, tmp);
        }
    };
    
    // get the type of piece
    this.getType = function() {
        return pieceType;
    };
    
    this.getBlockXCoord = function(index) {
         return coordinates[index][0];
    };
  
    this.getBlockYCoord = function(index) {
        return coordinates[index][1];
    };

    this.getMinX = function() {
        var tmp = coordinates[0][0];
        for(var i = 1 ; i < 4 ; i++) {
            if(tmp > coordinates[i][0]) {
                tmp = coordinates[i][0];
            }
        }
        return tmp;
    };

    this.getMaxX = function() {
        var tmp = coordinates[0][0];
        for(var i = 1 ; i < 4 ; i++) {
            if(tmp < coordinates[i][0]) {
                tmp = coordinates[i][0];
            }
        }
        return tmp;
    };

    this.getMinY = function() {
        var tmp = coordinates[0][1];
        for(var i = 1; i < 4; i++) {
            if(tmp > coordinates[i][1]) {
                tmp = coordinates[i][1];
            }
        }
        return tmp;
    };

    this.getMaxY = function() {
        var tmp = coordinates[0][1];
        for(var i = 1; i < 4; i++) {
            if (tmp < coordinates[i][1]) {
                tmp = coordinates[i][1];
            }
        }
        return tmp;
    };

    this.setBlockXCoord = function(index, value) {
        coordinates[index][0] = value;
    };

    this.setBlockYCoord = function(index, value) {
        coordinates[index][1] = value;
    };

    this.setBlockCoord = function(index, x, y) {
        coordinates[index][0] = x;
        coordinates[index][1] = y;
    };
}

// seven types of pieces
TetrixPiece.pieceTypes = [[[ 0,-1],
                           [ 0, 0],
                           [-1, 0],
                           [-1, 1]],
                             
                          [[ 0,-1],
                           [ 0, 0],
                           [ 1, 0],
                           [ 1, 1]],

                          [[ 0,-1],
                           [ 0, 0],
                           [ 0, 1],
                           [ 0, 2]],

                           [[-1, 0],
                            [ 0, 0],
                            [ 1, 0],
                            [ 0, 1]],

                           [[ 0, 0],
                            [ 1, 0],
                            [ 0, 1],
                            [ 1, 1]],

                           [[-1,-1],
                            [ 0,-1],
                            [ 0, 0],
                            [ 0, 1]],

                           [[ 1,-1],
                            [ 0,-1],
                            [ 0, 0],
                            [ 0, 1]]];

function Color(r, g, b) {
    this.r = r;
    this.g = g;
    this.b = b;
    this.toString = function() {
        return 'rgb(' + [this.r, this.g, this.b].join() + ')';
    };
}
                            
function TetrixBox(boxWidthInBlk, boxHeightInBlk, 
                   blockWidth,  blockHeight) {
    boxWidthInBlk = boxWidthInBlk || 4;
    boxHeightInBlk = boxHeightInBlk || 4;
    blockWidth = blockWidth || 25;
    blockHeight = blockHeight || 25;
    
    var isBlockBorder = false;
    var tetrixPieces = [];
    for(var i = 0; i < 7; i++) {
        tetrixPieces[i] = new TetrixPiece(i + 1);
    }
    
    var backgroundColor = new Color(255, 255, 255);
    var width = boxWidthInBlk * blockWidth;
    var height = boxHeightInBlk * blockHeight;
    
    var tetrixImages = null;
    var currentPiece = currentImage = null;

    this.setTetrixImages = function(images) {
        tetrixImages = images;
    };
    
    this.getTetrixImages = function() {
        return tetrixImages;
    };
    
    this.generate = function() {
        var index = parseInt(Math.random() * 7);
        currentPiece = tetrixPieces[index];
        currentImage = tetrixImages[index];
    };
    
    this.getTetrixPiece = function() {
        return currentPiece;
    };
    
    this.getTetrixImage = function() {
        return currentImage;
    };

    this.setBackgroundColor = function(backgroundColor) {
        backgroundColor = backgroundColor;
    }
    
    this.getBackgroundColor = function() {
        return backgroundColor;
    };
    
    this.setBlockBorder = function(flag) {
        isBlockBorder = flag;
    };
    
    this.isBlockBorder = function() {
        return isBlockBorder;
    };
    
    this.getBlockWidth = function() {
        return blockWidth;
    };
    
    this.getBlockHeight = function() {
        return blockHeight;
    };
    
    this.getWidth = function() {
        return width;
    };
    
    this.getHeight = function() {
        return height;
    };
    
    function drawBlock(context, x, y) {
        context.drawImage(currentImage, x * blockWidth, y * blockHeight, blockWidth, blockHeight);
        if(isBlockBorder) {
            context.beginPath();
            context.strokeStyle = 'rgb(150, 150, 150)';
            context.rect(x * blockWidth, y * blockHeight, blockWidth, blockHeight);
            context.stroke();
        }
    }

    this.paint = function(context) {
        // draw box background
        context.fillStyle = backgroundColor.toString();
        context.fillRect(0, 0, width, height);
        for(var i = 0; i < 4; i++) {
            drawBlock(context, currentPiece.getBlockXCoord(i) + 1, currentPiece.getBlockYCoord(i) + 1);
        }
    }
}

function TetrixGround(groundWidthInBlk, groundHeightInBlk) {
    var groundWidthInBlk = groundWidthInBlk || 10;
    var groundHeightInBlk = groundHeightInBlk || 20;
        
    var tetrixPiece = new TetrixPiece();
    var testPiece = new TetrixPiece();
    var ground = [];
    for(var i = 0; i < groundWidthInBlk; i++) {
        ground[i] = [];
        for(var j = 0; j < groundHeightInBlk; j++) {
            ground[i][j] = 0;
        }
    }
        
    var xOffset = parseInt(groundWidthInBlk / 2) - 1;
    var yOffset = 1;
    var emptyLines = groundHeightInBlk;
    
    var emptyLines = 0;
    var removedLines = 0;
    var score = 0;
    
    var isGameover = false;
    
    var isOperable = true;
    
    this.isMovable = function(xStep, yStep) {
        for(var i = 0; i < 4; i++) {
            var x = tetrixPiece.getBlockXCoord(i) + xOffset + xStep;
            var y = tetrixPiece.getBlockYCoord(i) + yOffset + yStep;

            if(x < 0 || x >= groundWidthInBlk || y >= groundHeightInBlk) {
                return false;
            }

            if(ground[x][y] != 0) {
                return false;
            }
        }

        return true;
    };
    
    this.addPieceOfType = function(pieceType) {
        tetrixPiece.initialize(pieceType);
        testPiece.initialize(pieceType);
        
        xOffset = groundWidthInBlk / 2 - 1;
        if(tetrixPiece.getMinY() < 0) {
            yOffset = Math.abs(tetrixPiece.getMinY());
        }
        else {
            yOffset = 0;
        }
        
        for(var i = 0; i < 4; i++) {
            var x = tetrixPiece.getBlockXCoord(i) + xOffset;
            var y = tetrixPiece.getBlockYCoord(i) + yOffset;

            if(ground[x][y] != 0) {
                isGameover = true;
            }
        }
    };
    
    this.reset = function() {
        emptyLines = groundHeightInBlk;
        score = 0;
        removedLines = 0;
        isGameover = false; 
        isOperable = true;
        
        xOffset = parseInt(groundWidthInBlk / 2) - 1;
        if(tetrixPiece.getMinY() < 0) {
            yOffset = Math.abs(tetrixPiece.getMinY());
        }
        else {
            yOffset = 0;
        }
        
        for(var i = 0; i < groundWidthInBlk; i++) {
            for(var j = 0; j < groundHeightInBlk; j++) {
                ground[i][j] = 0;
            }
        }
    };
    
    this.moveTetrixLeft = function() {
        if(this.isMovable(-1, 0)) {
            xOffset--;
        }
    };

    this.moveTetrixRight = function() {
        if(this.isMovable(1, 0)) {
            xOffset++;
        }
    };

    this.moveTetrixDown = function() {
        if(this.isMovable(0, 1) && isOperable) { 
            yOffset++; 
        }
    };

    this.dropTetrix = function() {
        while(this.isMovable(0, 1) && isOperable) {
            yOffset++;
        }
    };

    this.rotateTetrix = function(clockwise) {
        for(var i = 0; i < 4; i++) {
            testPiece.setBlockCoord(i, tetrixPiece.getBlockXCoord(i), tetrixPiece.getBlockYCoord(i));
        }

        if(clockwise) {
            testPiece.rotateRight();
        }
        else {
            testPiece.rotateLeft();
        }

        for(var i = 0; i < 4; i++) {
            var x = testPiece.getBlockXCoord(i) + xOffset;
            var y = testPiece.getBlockYCoord(i) + yOffset;

            if(x < 0 || x >= groundWidthInBlk || y >= groundHeightInBlk || y < 0) {
                return;
            }

            if(ground[x][y] != 0) {
                return;
            }
        } 
       
        for(var i = 0; i < 4; i++) {
            tetrixPiece.setBlockCoord(i, testPiece.getBlockXCoord(i), testPiece.getBlockYCoord(i));
        }
    };
    
    this.updateGround = function() {
        isOperable = false;
        
        if(!isGameover && !this.isMovable(0, 1)) {
            // touch the bottom of playground or the top of one piece 
            for(var i = 0; i < 4; i++) {
                var x = tetrixPiece.getBlockXCoord(i) + xOffset;
                var y = tetrixPiece.getBlockYCoord(i) + yOffset;
                ground[x][y] = tetrixPiece.getType();
            }
        
            var pieceTop = tetrixPiece.getMinY() + yOffset;
            if(pieceTop < emptyLines) {
                emptyLines = pieceTop;
            }
        
            removeFullLines();
        }
        
        isOperable = true;
    };
    
    function removeFullLines() {
        var count = 0;
        for(var j = groundHeightInBlk - 1; j > emptyLines; j--) {
            var isFullLine = true;
            for(var i = 0; i < groundWidthInBlk; i++) {
                if(ground[i][j] == 0) {
                    isFullLine = false;
                    break;
                }
            }

            if(isFullLine) {
                count++;
                for(var k = j; k > emptyLines; k--) {
                    for(var i = 0; i < groundWidthInBlk; i++) {
                        if(ground[i][k] != ground[i][k-1]) {
                            ground[i][k] = ground[i][k-1];
                        }
                    }
                }
                
                for(var i = 0; i < groundWidthInBlk; i++) {
                    ground[i][emptyLines] = 0;
                }
                emptyLines++;
                j++;
                
                removedLines++;
            }
        }
        
        score = score + parseInt(Math.pow(2, count));
    };
    
    this.getGroundHeightInBlk = function() {
        return groundHeightInBlk;
    };
    
    this.getGroundWidthInBlk = function() {
        return groundWidthInBlk;
    };
    
    this.getTetrixPiece = function() {
        return tetrixPiece;
    };
    
    this.setTetrixPiece = function(tetrixPiece) {
        tetrixPiece = tetrixPiece;
    };
    
    this.getGroundInfo = function() {
        return ground;
    };
    
    this.isGameover = function() {
        return isGameover;
    };
    
    this.getScore = function() {
        return score;
    };
    
    this.getRemovedLines = function() {
        return removedLines;
    };
    
    this.getXOffset = function() {
        return xOffset;
    };
    
    this.getYOffset = function() {
        return yOffset;
    };
}

function TetrixStackArea(tetrixBox, tetrixGround) {
    var backgroundColor = new Color(255, 255, 255);
    var width = tetrixGround.getGroundWidthInBlk() * tetrixBox.getBlockWidth();
    var height = tetrixGround.getGroundHeightInBlk() * tetrixBox.getBlockHeight();
                
    var isBlockBorder = false;
    
    this.setBackgroundColor = function(color) {
        backgroundColor = color;
    };
    
    this.getBackgroundColor = function() {
        return backgroundColor;
    };
    
    this.setBlockBorder = function(flag) {
        isBlockBorder = flag;
    };
    
    this.isBlockBorder = function() {
        return isBlockBorder;
    };
    
    this.getWidth = function() {
        return width;
    };
    
    this.getHeight = function() {
        return height;
    };
        
    function drawBlock(context, image, x, y) {
        context.drawImage(image, x * tetrixBox.getBlockWidth(), y * tetrixBox.getBlockHeight(), 
                tetrixBox.getBlockWidth(), tetrixBox.getBlockHeight());
        
        if(isBlockBorder) {
            context.beginPath();
            context.strokeStyle = 'rgb(150, 150, 150)';
            context.drawRect(x * tetrixBox.getBlockWidth(), y * tetrixBox.getBlockHeight(), 
                    tetrixBox.getBlockWidth(), tetrixBox.getBlockHeight());
            context.stroke();
        }
    }
    
    this.paint = function(context) {
        // clean previous screen
        context.fillStyle = backgroundColor.toString();
        context.fillRect(0, 0, width, height);

        // draw current piece
        for(var i = 0; i < 4; i++) {
            drawBlock(context, tetrixBox.getTetrixImages()[tetrixGround.getTetrixPiece().getType() - 1],
                    tetrixGround.getTetrixPiece().getBlockXCoord(i) + tetrixGround.getXOffset(),
                    tetrixGround.getTetrixPiece().getBlockYCoord(i) + tetrixGround.getYOffset());
        }

        // draw stack of pieces
        for(var i = 0; i < tetrixGround.getGroundWidthInBlk(); i++) {
            for(var j = 0; j < tetrixGround.getGroundHeightInBlk(); j++) {
                if(tetrixGround.getGroundInfo()[i][j] == 0) {
                    continue;
                }
                drawBlock(context, tetrixBox.getTetrixImages()[tetrixGround.getGroundInfo()[i][j] - 1], i, j);
            }
        }

        if(tetrixGround.isGameover()) {
            context.save();
            context.shadowOffsetX = 1;
            context.shadowOffsetY = 1;
            context.shadowColor = 'black';
            context.font = tetrixBox.getBlockWidth() + 'px "Arial Black"';
            context.fillStyle = 'red';
            context.fillText('Game over', width / 5, height / 2);
            context.restore();
        }
    };
}
