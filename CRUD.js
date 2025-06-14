const express=require ('express')
const mongoose=require('mongoose')
const app=express();
const path = require('path');
app.use(express.json());
const TEMP=require('./model/app');
mongoose.connect('mongodb://localhost:27017/CRUD')
.then(()=>console.log('connection successful with mongo Db'))
.catch((err)=>console.log('not connected',err))

app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'public', 'CRUD.html'));
});
app.get('/readalldata', async (req, res) => {  //showing as alert and console 
    try {
        console.log("Fetching records from database...");
        const data = await TEMP.find();
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
app.get('/readspecificdata/:id', async (req, res) => {
    try {
        const data = await TEMP.findOne({ _id: req.params.id });
        if (!data) {
            return res.status(404).json({ success: false, message: "Record not found" });
        }
        res.status(200).json({ success: true, record: data });
    } catch (error) {
        console.error("Error fetching specific record:", error);
        res.status(500).json({ success: false, message: error.message });
    }
});
app.post('/create', async (req, res) => {
    try {
        const appData = new TEMP(req.body);  
        const result = await appData.save();
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

        const result = await TEMP.findByIdAndUpdate(id, updateData, { new: true });

       if(result) {
            res.status(200).json({ success: true, message: "Record updated successfully", result });
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
    let id = req.params.id;
    let result = await TEMP.findByIdAndDelete(id);
    if (result) {
        res.status(200).json({ success: true, message: "Record deleted successfully" });
        deletedata = result;
    } else {
        res.status(404).json({ success: false, message: "Record not found" });
    }
}
);


app.listen(3000, () => {
    console.log('Server is running on http://localhost:3000');
});