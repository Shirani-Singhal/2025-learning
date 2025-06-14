const mongoose = require('mongoose');
const appSchema = new mongoose.Schema({
    _id: Number,
    employee_ID: { type: Number, required: true },
    name: { type: String, required: true },
    age: { type: Number, required: true }
});

const App = mongoose.model('App', appSchema, 'app2');
module.exports = App;