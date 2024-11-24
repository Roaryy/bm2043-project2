// server/routes/nodes.js

const router = require('express').Router();
const Node = require('../models/Node');

// Get all nodes
router.get('/', async (req, res) => {
  try {
    const nodes = await Node.find();
    res.json(nodes);
  } catch (err) {
    console.error('Error retrieving nodes:', err);
    res.status(500).json({ error: 'Server error while retrieving nodes' });
  }
});

// Add a new node
router.post('/add', async (req, res) => {
  try {
    const { label } = req.body;

    if (!label || typeof label !== 'string') {
      return res.status(400).json({ error: 'Invalid node label' });
    }

    const newNode = new Node({ label });
    await newNode.save();

    res.status(201).json({ message: 'Node added!', node: newNode });
  } catch (err) {
    console.error('Error adding node:', err);
    res.status(500).json({ error: 'Server error while adding node' });
  }
});

// Delete a node
router.delete('/:id', async (req, res) => {
  try {
    const nodeId = req.params.id;
    await Node.findByIdAndDelete(nodeId);
    res.json({ message: 'Node deleted.' });
  } catch (err) {
    console.error('Error deleting node:', err);
    res.status(500).json({ error: 'Server error while deleting node' });
  }
});

module.exports = router;
