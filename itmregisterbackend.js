const express = require('express');
const mongoose = require('mongoose');
const app = express();
const path = require('path');
app.use(express.json());
const ItmRegister = require('./model/itmregister');
mongoose.connect('mongodb://localhost:27017/itm')
    .then(() => console.log('Connection successful with MongoDB'))
    .catch((err) => console.log('Not connected', err));
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'itmregisterpage.html'));
});
app.get('/readalldata', async (req, res) => {
    try {
        console.log("Fetching records from database...");
        const data = await ItmRegister.find();
        console.log("Fetched Records:", JSON.stringify(data));

        if (!data || data.length === 0) {
            return res.status(404).json({ success: false, message: "No records found" });
        }

        res.status(200).json({ success: true, records: data });
    } catch (error) {
        console.error("Error fetching records:", error);
        res.status(500).json({ success: false, message: error.message });
    }
});
app.post('/create', async (req, res) => {
    try {
        const itmData = new ItmRegister(req.body);
        const result = await itmData.save();
        res.status(201).json({ success: true, message: "Record added successfully", result });
    } catch (error) {
        console.error("Error saving:", error);
        res.status(400).json({ success: false, message: error.message });
    }
});
app.put('/update/:id', async (req, res) => {
    try {
        const id = req.params.id;  // Get ID from URL
        const updateData = req.body;  // Get updated data

        const result = await ItmRegister.findByIdAndUpdate(id, updateData, { new: true });

       if(result) {
            res.status(200).json({ success: true, message: "Record updated successfully", result });
            alert("record updated successfully",id);
        }
        else {
            res.status(404).json({ success: false, message: "Record not found" });
        }
    } catch (error) {
        console.error("Error updating record:", error);
        res.status(500).json({ success: false, message: error.message });
    }
}
);  
app.delete('/delete/:id', async (req, res) => {
    try {
        const id = req.params.id;  // Get ID from URL
        const result = await ItmRegister.findByIdAndDelete(id);

        if (result) {
            res.status(200).json({ success: true, message: "Record deleted successfully" });
        } else {
            res.status(404).json({ success: false, message: "Record not found" });
        }
    } catch (error) {
        console.error("Error deleting record:", error);
        res.status(500).json({ success: false, message: error.message });
    }
});
app.listen(3000, () => {
    console.log('Server is running on port http://localhost:3000');
});