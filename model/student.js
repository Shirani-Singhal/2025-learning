const mongoose = require('mongoose');

const studentSchema = mongoose.Schema({
    _id:  Number,
fields: {
    name: { type: String, required: true },
    age: { type: Number, required: true },  // Age should be a number
    gender: { type: String, required: true },
    department: { type: String, required: true },
    marks: {
        maths: { type: Number, required: true },
        english: { type: Number, required: true },
        hindi: { type: Number, required: true },
        chemistry: { type: Number, required: true },
        physics: { type: Number, required: true }
    },
    city: { type: String, required:  false, default: null },
    sports: { type: String, required: true }
}
});

const Student = mongoose.model('Student', studentSchema,'students');
module.exports = Student;