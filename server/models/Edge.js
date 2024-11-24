// server/models/Edge.js

const mongoose = require('mongoose');

const Schema = mongoose.Schema;

const edgeSchema = new Schema(
  {
    from: {
      type: Schema.Types.ObjectId,
      ref: 'Node',
      required: true,
    },
    to: {
      type: Schema.Types.ObjectId,
      ref: 'Node',
      required: true,
    },
  },
  {
    timestamps: true,
  }
);

const Edge = mongoose.model('Edge', edgeSchema);

module.exports = Edge;
