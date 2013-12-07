(function(global) {
    var XD = function(selector, container) {
        return new XD.mth.init(selector, container);
    };
    
    var utils = {
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
					i < length && callback.call(obj[i], value, i) !== false; value = obj[++i] ) {}
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
    
    XD.Event = function(original) {
        if(!this.stopPropagation) {
            return new XD.Event(original);
        }
        // 複製特性
        this.original = original;
        this.type = original.type;
        this.target = original.target || original.srcElement;
        // .. 標準化其它特性
    };
    
    XD.Event.prototype = {
        stopPropagation: function() {
            if(this.original.stopPropagation) {
                this.original.stopPropagation();
            }
            else {
                this.original.cancelBubble = true;
            }
        }
        // 標準化其它方法
    };
    
    if(document.addEventListener) {
        utils.bind = function(element, eventType, handler) {
            element.addEventListener(eventType, function(event) {
                var result = handler.call(event.currentTarget, XD.Event(event));
                if(result === false) {
                    event.preventDefault();
                }
                return result;
            }, false);
        };
        utils.unbind = function(element, eventType, handler) {
            element.removeEventListener(eventType, handler, false);
        };
    }
    else if(document.attachEvent) {
        utils.bind = function(element, eventType, handler) {
            element.attachEvent('on' + eventType, function() {
                var result = handler.call(element, XD.Event(window.event));
                if(result === false) {
                    window.event.returnValue = false;
                }
                return result;
            });
        };
        utils.unbind = function(element, eventType, handler) {
            element.detachEvent(eventType, handler);
        };
    }
    
   function extend(target, source) {
        utils.each(source, function(value, key) {
            target[key] = value;
        });
   }
   
   extend(XD, utils);
   XD.extend = extend;
   XD.props = {
        'for': 'htmlFor',
        'class': 'className',
        readonly: 'readOnly',
        maxlength: 'maxLength',
        cellspacing: 'cellSpacing',
        rowspan: 'rowSpan',
        colspan: 'colSpan',
        tabindex: 'tabIndex',
        usemap: 'useMap',
        frameborder: 'frameBorder'
    };
   
   XD.mth = XD.prototype = {
       init: function(selector, container) {
           // 這是元素
           if(selector.nodeType) {
               this[0] = selector;
               this.length = 1;
               return this;
           }
           
           if(container && container[0]) {
               container = container[0];
           }
           else {
               container = document;
           }
           
           var elements = [];
           XD.each(selector.split(','), function(text) {
               text = XD.trim(text);
               if(text.charAt(0) === '#') {
                   elements.push(container.getElementById(text.substring(1)));
               }
               else if(text.charAt(0) === '<') {
                   elements.push(document.createElement(text.substring(1, text.length - 1)));
               }
               else {
                   XD.each(container.getElementsByTagName(text), function(element) {
                       elements.push(element);
                   });
                   
               }
           });
           XD.extend(this, elements);
           this.length = elements.length;
       },
       size: function() {
           return this.length;
       },
       isEmpty: function() {
           return this.length === 0;
       },
       each: function(callback) {
           return XD.each(this, callback);
       },
       html: function(value) {
           if(value === undefined) {
               return this[0] && this[0].nodeType === 1 ?
				        this[0].innerHTML : null;
           }
           else {
               return XD.each(this, function(element) {
                   if(element.nodeType === 1) {
                       element.innerHTML = value;
                   }
               });
           }
       },
       attr: function(name, value) {
           name = XD.props[name] || name;
           if(value === undefined) {
               return this[0] && this[0].nodeType !== 3 && this[0].nodeType !== 8 ?
                        this[0][name] : undefined;
           }
           else {
               return XD.each(this, function(element) {
                   if(element.nodeType !== 3 && element.nodeType !== 8) {
                       element[name] = value;
                   }
               });
           }       
       },
       val: function(value) {
           // 先只處理 <input> 元素
           if(value === undefined) {
               return this[0] && this[0].nodeName === 'INPUT' ? 
                       this[0].value : null;
           }
           else {
               return XD.each(this, function(element) {
                   if(element.nodeName === 'INPUT') {
                       element.value = value;
                   }
               });
           }
       },
       append: function(childs) {
           if(typeof childs === 'string' || childs.nodeType) {
               childs = XD(childs);
           }
           
           if(this.length === 1) { // 只有一個父節點
               var parent = this[0];
               XD.each(childs, function(child) {
                   parent.appendChild(child);
               });
           }
           else if(this.length > 1){ // 有多個父節點
               XD.each(this, function(parent) {
                   childs.each(function(child) {
                       // 複製子節點
                       var container = document.createElement('div');
                       container.appendChild(child);
                       container.innerHTML = container.innerHTML;
                       parent.appendChild(container.firstChild);
                   });
               });
           }
           return this;
       },
       appendTo: function(parents) {
           if(typeof parents === 'string' || parents.nodeType) {
               parents = XD(parents);
           }
           return parents.append(this);
       },
       remove: function() {
           return XD.each(this, function(element) {
               element.parentNode.removeChild(element);
           });
       },
       bind: function(eventType, handler) {
           return XD.each(this, function(element) {
               XD.bind(element, eventType, handler);
           });
       },
       unbind: function(eventType, handler) {
           return XD.each(this, function(element) {
               XD.unbind(element, eventType, handler);
           });
       },
       click: function(handler) {
           return this.bind('click', handler);
       }
   };
   
   
   XD.mth.init.prototype = XD.mth;

   global.XD = XD;
})(this);