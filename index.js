const express=require ('express')
const mongoose=require('mongoose')
const app=express();
const path = require('path');
app.use(express.json());
const TEMP = require('./model/student');
mongoose.connect('mongodb://localhost:27017/college3db')
.then(()=>console.log('connection successful with mongo Db'))
.catch((err)=>console.log('not connected',err))

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'index.html'));
});
app.get('/readalldata', async (req, res) => {
    try {
        console.log("Fetching records from database...");
        const data = await TEMP.find();
        console.log("Fetched Records:", data);

        if (!data || data.length === 0) {
            return res.status(404).json({ success: false, message: "No records found" });
        }

        res.status(200).json({ success: true, records: data });
    } catch (error) {
        console.error("Error fetching records:", error);
        res.status(500).json({ success: false, message: error.message });
    }
});

app.get('/readspecificdata/:id', async (req, res) => {
    try {
        let id = req.params.id;
        console.log("Fetching Record for ID:", id); // Debugging Step
        const data = await TEMP.findById(id);
        
        if (data) {
            console.log("Full Record:", JSON.stringify(data, null, 2)); // ✅ Print whole data
            return res.status(200).json({ success: true, record: data, message: "Record found" });
        } 
        
        res.status(404).json({ success: false, message: "Record not found" });
    } catch (error) {
        console.error("Error retrieving record:", error);
        res.status(500).json({ success: false, message: error.message });
    }
});

app.post('/create', async (req, res) => {
    try {
        console.log("Received Data:", req.body); // Debugging step
        const student = new TEMP(req.body);  
        const result = await student.save();
        res.status(201).json({ success: true, message: "Record added successfully", result });
    } catch (error) {
        console.error("Error saving:", error);
        res.status(400).json({ success: false, message: error.message });
    }
});
app.put('/update/:id', async (req, res) => {
    try {
        console.log("Updating record for ID:", req.params.id, "Received Data:", req.body); 
        
        const data = await TEMP.findByIdAndUpdate(
            req.params.id,
            { $set: { fields: req.body.fields } }, 
            { new: true }
        );

        if (!data) {
            console.error("Record not found:", req.params.id); 
            return res.status(404).json({ success: false, message: "Data not found" });
        }

        console.log("Updated Record:", data); 
        res.status(200).json({ success: true, message: "Record updated successfully", data });
    } catch (error) {
        console.error("Error updating record:", error); 
        res.status(400).json({ success: false, message: error.message });
    }
});
app.delete('/delete/:id',async(req,res)=>{
    try {
        const data = await TEMP.findByIdAndDelete(req.params.id);
        if (!data) {
            return res.status(404).json({ success: false, message: "Data not found" });
        }
         res.status(200).json({ success: true, message: "Data deleted successfully", deletedRecord: data });
    } catch (error) {
        console.error("Error deleting record:", error); 
        res.status(500).json({ success: false, message: error.message });
    }
});

app.listen(3000,()=>{
    console.log("server running at http://localhost:3000");
})