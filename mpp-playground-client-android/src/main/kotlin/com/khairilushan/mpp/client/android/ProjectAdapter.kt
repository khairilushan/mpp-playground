package com.khairilushan.mpp.client.android

import android.support.v7.widget.RecyclerView
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import com.bumptech.glide.Glide
import com.khairilushan.mpp.viewmodel.ProjectItemViewModel

class ProjectAdapter : RecyclerView.Adapter<ProjectAdapter.ViewHolder>() {

    private var data = listOf<ProjectItemViewModel>()

    override fun onCreateViewHolder(p0: ViewGroup, p1: Int) =
        ViewHolder(LayoutInflater.from(p0.context).inflate(R.layout.list_item_project, p0, false))

    override fun getItemCount() = data.size

    override fun onBindViewHolder(p0: ViewHolder, p1: Int) {
        p0.bind(data[p1])
    }

    fun setItems(projects: List<ProjectItemViewModel>) {
        data = projects
        notifyDataSetChanged()
    }

    class ViewHolder(view: View) : RecyclerView.ViewHolder(view) {
        val textTitle: TextView by lazy { view.findViewById<TextView>(R.id.textTitle) }
        val textDescription: TextView by lazy { view.findViewById<TextView>(R.id.textDescription) }
        val textAuthor: TextView by lazy { view.findViewById<TextView>(R.id.textAuthor) }
        val avatarImageView: ImageView by lazy { view.findViewById<ImageView>(R.id.imagePhoto) }

        fun bind(viewModel: ProjectItemViewModel) {
            textTitle.text = viewModel.title
            textDescription.text = viewModel.desc
            textAuthor.text = viewModel.author
            Glide.with(itemView.context).load(viewModel.avatarUrl).into(avatarImageView)
        }
    }

}
