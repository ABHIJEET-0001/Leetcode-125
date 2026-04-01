var expect = function(val) {
    return {
        toBe: function(value) {
            if (val === value) {
                return true;
            } else {
                throw new Error("Not Equal");
            }
        },
        notToBe: function(value) {
            if (val !== value) {
                return true;
            } else {
                throw new Error("Equal");
            }
        }
    };
};