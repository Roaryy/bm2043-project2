// server/models/Node.js

const mongoose = require('mongoose');

const Schema = mongoose.Schema;

const nodeSchema = new Schema(
  {
    label: {
      type: String,
      required: true,
      trim: true,
    },
  },
  {
    timestamps: true,
  }
);

const Node = mongoose.model('Node', nodeSchema);

module.exports = Node;
