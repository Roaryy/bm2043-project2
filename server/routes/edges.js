// server/routes/edges.js

const router = require('express').Router();
const Edge = require('../models/Edge');

// Get all edges
router.get('/', async (req, res) => {
  try {
    const edges = await Edge.find();
    res.json(edges);
  } catch (err) {
    console.error('Error retrieving edges:', err);
    res.status(500).json({ error: 'Server error while retrieving edges' });
  }
});

// Add a new edge
router.post('/add', async (req, res) => {
  try {
    const { from, to } = req.body;

    if (!from || !to) {
      return res.status(400).json({ error: 'Edge must have from and to nodes' });
    }

    const newEdge = new Edge({ from, to });
    await newEdge.save();

    res.status(201).json({ message: 'Edge added!', edge: newEdge });
  } catch (err) {
    console.error('Error adding edge:', err);
    res.status(500).json({ error: 'Server error while adding edge' });
  }
});

// Delete an edge
router.delete('/:id', async (req, res) => {
  try {
    const edgeId = req.params.id;
    await Edge.findByIdAndDelete(edgeId);
    res.json({ message: 'Edge deleted.' });
  } catch (err) {
    console.error('Error deleting edge:', err);
    res.status(500).json({ error: 'Server error while deleting edge' });
  }
});

module.exports = router;
