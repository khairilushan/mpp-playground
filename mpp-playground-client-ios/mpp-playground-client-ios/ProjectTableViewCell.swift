//
//  ProjectTableViewCell.swift
//  mpp-playground-client-ios
//
//  Created by Khairil Ushan on 8/7/18.
//  Copyright © 2018 Khairil Ushan. All rights reserved.
//

import UIKit
import Mpp
import Kingfisher

class ProjectTableViewCell: UITableViewCell, ReusableCell {

    @IBOutlet weak var imageAvatar: UIImageView!
    @IBOutlet weak var textTitle: UILabel!
    @IBOutlet weak var textDescription: UILabel!
    @IBOutlet weak var textAuthor: UILabel!

    static var height: CGFloat {
        return 98
    }

    override func awakeFromNib() {
        super.awakeFromNib()
        textDescription.numberOfLines = 0
        textAuthor.bottomAnchor.constraint(equalTo: contentView.bottomAnchor, constant: -8)
            .isActive = true
    }

    func bind(with project: MppProject) {
        textTitle.text = project.title
        textDescription.text = project.desc
        textAuthor.text = project.author
        if let avatarUrl = URL(string: project.avatarUrl) {
            imageAvatar.kf.setImage(with: avatarUrl)
        }
    }

}

protocol ReusableCell {
    static var identifier: String { get }
    static var nib: UINib { get }
}

extension ReusableCell {
    static var identifier: String {
        return String(describing: self)
    }

    static var nib: UINib {
        return UINib(nibName: identifier, bundle: nil)
    }
}
