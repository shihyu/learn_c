(function(global) {
    var XD = {
        trim: function(text) {
            return (text || '').replace( /^(\s|\u00A0)+|(\s|\u00A0)+$/g, '');
        },
        isArray: function(obj) {
            return Object.prototype.toString.call(obj) === '[object Array]';
        },
        isFunction: function(obj) {
            return Object.prototype.toString.call(obj) === '[object Function]';
        },
        each: function(obj, callback) {
            var length = obj.length,
                isObj = (length === undefined) || this.isFunction(obj);
            if (isObj) {
                for(var name in obj) {
                    if(callback.call(obj[name], obj[name], name) === false ) {
                        break;
                    }
                }
            }
            else {
                for(var i = 0, value = obj[0];
                    i < length && callback.call(obj[i], value, i) !== false;
                    value = obj[++i] ) {}
            }
            return obj;
        },
        makeArray: function(arrayLike) {
            if(arrayLike.length != null) {
                return Array.prototype.slice.call(arrayLike, 0)
                        .filter(function(ele) { return ele !== undefined; });
            }
            return [];
        }
    };
    global.XD = XD;
})(this);