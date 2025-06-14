const mongoose = require('mongoose');
const itmRegisterSchema = mongoose.Schema({
    _id: Number,
    full_name: { type: String, required: true },
    email: { type: String, required: true },
    username: { type: String, required: true },
    password: { type: String, required: true },
    confirm_password: { type: String, required: true },
});
const ItmRegister = mongoose.model('ItmRegister', itmRegisterSchema, 'folks1');
module.exports = ItmRegister;