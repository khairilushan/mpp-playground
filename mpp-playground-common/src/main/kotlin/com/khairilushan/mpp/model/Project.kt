package com.khairilushan.mpp.model

import com.khairilushan.mpp.viewmodel.ProjectItemViewModel

data class Project(
  val title: String,
  val desc: String,
  val author: String,
  val avatarUrl: String,
  val pageUrl: String
) {
    fun mapToViewModel() = ProjectItemViewModel(title, desc, author, avatarUrl, pageUrl)
}
